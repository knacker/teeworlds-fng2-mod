/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <base/vmath.h>

class CCollision
{
	class CTile *m_pTiles;
	int m_Width;
	int m_Height;
	class CLayers *m_pLayers;

	bool IsTile(int x, int y, int Flag=COLFLAG_SOLID) const;
	int GetTile(int x, int y) const;

public:
	enum
	{
		COLFLAG_SOLID=1,
		COLFLAG_DEATH=2,
		COLFLAG_NOHOOK=4,
	};

	enum
	{
		FLAG_SPIKE_NORMAL = 1 << 0,
		FLAG_SPIKE_RED = 1 << 1,
		FLAG_SPIKE_BLUE = 1 << 2,
		FLAG_SPIKE_GOLD = 1 << 3,
		FLAG_SPIKE_GREEN = 1 << 4,
		FLAG_SPIKE_PURPLE = 1 << 5,
	};

	enum
	{
		COLFLAG_SPIKE_NORMAL = FLAG_SPIKE_NORMAL << 16,
		COLFLAG_SPIKE_RED = FLAG_SPIKE_RED << 16,
		COLFLAG_SPIKE_BLUE = FLAG_SPIKE_BLUE << 16,
		COLFLAG_SPIKE_GOLD = FLAG_SPIKE_GOLD << 16,
		COLFLAG_SPIKE_GREEN = FLAG_SPIKE_GREEN << 16,
		COLFLAG_SPIKE_PURPLE = FLAG_SPIKE_PURPLE << 16,

		COLFLAG_SPIKE_SHIFT = 16,
	};

	enum
	{
		TILE_SPIKE_GOLD = 7,
		TILE_SPIKE_NORMAL = 8,
		TILE_SPIKE_RED = 9,
		TILE_SPIKE_BLUE = 10,
		TILE_SPIKE_GREEN = 14,
		TILE_SPIKE_PURPLE = 15,
	};

	CCollision();
	void Init(class CLayers *pLayers);
	bool CheckPoint(float x, float y, int Flag=COLFLAG_SOLID) const { return IsTile(round_to_int(x), round_to_int(y), Flag); }
	bool CheckPoint(vec2 Pos, int Flag=COLFLAG_SOLID) const { return CheckPoint(Pos.x, Pos.y, Flag); }
	int GetCollisionAt(float x, float y) const { return GetTile(round_to_int(x), round_to_int(y)); }
	int GetWidth() const { return m_Width; };
	int GetHeight() const { return m_Height; };
	int IntersectLine(vec2 Pos0, vec2 Pos1, vec2 *pOutCollision, vec2 *pOutBeforeCollision) const;
	void MovePoint(vec2 *pInoutPos, vec2 *pInoutVel, float Elasticity, int *pBounces) const;
	void MoveBox(vec2 *pInoutPos, vec2 *pInoutVel, vec2 Size, float Elasticity, bool *pDeath=0) const;
	bool TestBox(vec2 Pos, vec2 Size, int Flag=COLFLAG_SOLID) const;
};

#endif
