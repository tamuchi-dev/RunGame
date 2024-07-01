#include "GoldCoin.hpp"

namespace Game
{
	GoldCoin::GoldCoin() noexcept
	{
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/GoldCoin/01.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/GoldCoin/02.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/GoldCoin/03.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/GoldCoin/04.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/GoldCoin/05.png"));

		acquisitionScore = 50;

		Coin::Initialize();
	}
}