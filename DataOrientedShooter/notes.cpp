//struct gameplayManager
//{
//	enum typeIndex
//	{
//		xPosition,
//		yPosition
//	};
//	std::vector<float> xPositions;
//	std::vector<float> yPositions;
//	using signature = std::vector<bool>;
//	std::vector<signature> signatures;
//
//	size_t create()
//	{
//		size_t id = xPositions.size();
//		xPositions.push_back(0);
//		yPositions.push_back(0);
//		signatures.push_back({});
//		auto& sig = signatures[id];
//		sig.resize(2, false);
//
//		return id;
//	}
//
//	size_t count()
//	{
//		return xPositions.size();
//	}
//};
//
//struct enemyManager
//{
//
//};
//
//gameplayManager gameplay;
//auto player = gameplay.create();
//auto enemy = gameplay.create();
//gameplay.xPositions[player] = 5.0f;
//
//
//size_t count = gameplay.count();
//for (size_t i = 0; i < count; i++)
//{
//	auto& sig = gameplay.signatures[i];
//	if (sig[gameplayManager::xPosition])
//	{
//
//	}
//	gameplay.xPositions[i];
//
//}