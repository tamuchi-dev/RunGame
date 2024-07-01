#include "RedCoin.hpp"

namespace Game
{
	RedCoin::RedCoin() noexcept
	{
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RedCoin/01.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RedCoin/02.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RedCoin/03.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RedCoin/04.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RedCoin/05.png"));

		acquisitionScore = 100;

		Coin::Initialize();
	}
}