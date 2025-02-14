#include <../../Header/Gameplay/Ball/Ball.h>
#include<iostream>
namespace GamePlay
{
	
	Ball::Ball()
	{
		LoadTexture();
		InitializeVariable();
	}


	void Ball::LoadTexture()
	{
		if (!ballTexture.loadFromFile(ballTexturePath)) {
			throw std::runtime_error("Failed to load ball texture!");
		}
	}

	void Ball::InitializeVariable()
	{
		currentState = BallState::Idle;

		ballSprite.setTexture(ballTexture);
		ballSprite.setScale(scaleX, scaleY);
		ballSprite.setPosition(positonX, positionY);

		velocity = sf::Vector2f(ballSpeed, ballSpeed);
	}

	void Ball::MoveBall(Utility::TimeService* timeServices)
	{
		UpdateDelayTime(timeServices->GetDeltaTime());
		if (currentState == BallState::Moving) {
			ballSprite.move(velocity * timeServices->GetDeltaTime() * speedMultiplier);
		}
	}

	void Ball::UpdateDelayTime(float deltaTime)
	{
		if (currentState == BallState::Idle) {
			elapsedDelayTime += deltaTime;
			if (elapsedDelayTime >= delayDuration) {
				currentState = BallState::Moving;
			}
			else {
				return;
			}
		}
	}

	void Ball::OnCollision(Paddle* player1, Paddle* player2)
	{
		HandleBoundaryCollision();
		HandlePaddleCollision(player1, player2);
		HandleOutofBoundCollision();
	}

	void Ball::HandlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		const sf::RectangleShape& player1Sprite = player1->GetPaddleSprite();
		const sf::RectangleShape& player2Sprite = player2->GetPaddleSprite();

		sf::FloatRect ballBound = ballSprite.getGlobalBounds();
		sf::FloatRect player1Bound = player1Sprite.getGlobalBounds();
		sf::FloatRect player2Bound = player2Sprite.getGlobalBounds();

		if (ballBound.intersects(player1Bound) && velocity.x < 0) {
			velocity.x = -velocity.x;
			Sounds::SoundManager::PlaySoundEffect(Sounds::SoundType::BALL_BOUNCE);
		}
		if (ballBound.intersects(player2Bound) && velocity.x > 0) {
			velocity.x = -velocity.x;
			Sounds::SoundManager::PlaySoundEffect(Sounds::SoundType::BALL_BOUNCE);
		}
	}

	void Ball::HandleBoundaryCollision()
	{
		sf::FloatRect ballBound = ballSprite.getGlobalBounds();

		if ((ballBound.top <= topBoundary && velocity.y < 0) ||
			(ballBound.top + ballBound.height >= bottomBoundary && velocity.y > 0)) {
			velocity.y = -velocity.y;
			Sounds::SoundManager::PlaySoundEffect(Sounds::SoundType::BALL_BOUNCE);
		}
	}

	void Ball::HandleOutofBoundCollision()
	{
		sf::FloatRect ballBound = ballSprite.getGlobalBounds();

		if (ballBound.left <= leftBoundary)
		{
			UpdateLeftCollsionState(true);
			Sounds::SoundManager::PlaySoundEffect(Sounds::SoundType::BALL_BOUNCE);
			Reset();
		}
		else if (ballBound.left + ballBound.width >= rightBoundary)
		{
			UpdateRightCollsionState(true);
			Sounds::SoundManager::PlaySoundEffect(Sounds::SoundType::BALL_BOUNCE);
			Reset();
		}
	}

	bool Ball::IsLeftCollsionOccured()
	{
		return hadLeftCollison;
	}

	void Ball::UpdateLeftCollsionState(bool value)
	{
		hadLeftCollison = value;
	}

	bool Ball::IsRightCollsionOccured()
	{
		return hadRightCollison;
	}

	void Ball::UpdateRightCollsionState(bool value)
	{
		hadRightCollison = value;
	}

	void Ball::Reset()
	{
		ballSprite.setPosition(centerPositionX, centerPositionY);
		velocity = sf::Vector2f(ballSpeed, ballSpeed);
		currentState == BallState::Idle;
		elapsedDelayTime = 0.0f;
	}

	void Ball::Update(Paddle* player1, Paddle* player2, Utility::TimeService* timeServices)
	{
		MoveBall(timeServices);
		OnCollision(player1, player2);
	}

	void Ball::Render(sf::RenderWindow* gameWindow)
	{
		gameWindow->draw(ballSprite);
	}
}
