#pragma once
#ifndef __TILE__
#define __TILE__
#include "DisplayObject.h"
#include "Label.h"
#include "NeighbourgTile.h"

class Tile : public DisplayObject
{
public:
	// Constructor
	Tile();
	
	// Destructor
	~Tile();
	
	// Life-Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

	Tile* getNeighbourTile(NeighbourTile position);
	void setNeighbourTile(NeighbourTile position, Tile* Tile);
	float getTileCost()const;
	void setTileCost(float cost);
	void addLabels();
	void setLabelEnabled(const bool state)const;
	glm::vec2 getGridpos()const;
	void setGridpos(float col,float row);
private:

	Label* m_costLabel;
	Label* m_statusLabel;
	
	float m_cost;
	Tile* m_neighbours[NUM_OF_NEIGHBOUR_TILES];
	glm::vec2 m_gridpos;
};

#endif /* defined (__TILE__) */