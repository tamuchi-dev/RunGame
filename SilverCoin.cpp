#include "SilverCoin.hpp"

namespace Game
{
	SilverCoin::SilverCoin() noexcept
	{
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/SilverCoin/01.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/SilverCoin/02.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/SilverCoin/03.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/SilverCoin/04.png"));
		sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/SilverCoin/05.png"));

		acquisitionScore = 10;

		Coin::Initialize();
	}
}