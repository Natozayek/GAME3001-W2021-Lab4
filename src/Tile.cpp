#include "Tile.h"

#include "Config.h"
#include "TextureManager.h"
#include "Util.h"
#include <sstream>
#include <iomanip>

Tile::Tile(): m_cost(0.0f)
{
	setWidth(Config::TILE_SIZE);
	setHeight(Config::TILE_SIZE);
}

Tile::~Tile()
= default;

void Tile::draw()
{
	Util::DrawRect(getTransform()->position, getWidth(), getHeight());
}

void Tile::update()
{
}

void Tile::clean()
{
}

Tile* Tile::getNeighbourTile(const NeighbourTile position)
{
	return m_neighbours[position];
}

void Tile::setNeighbourTile(const NeighbourTile position, Tile* Tile)
{
	m_neighbours[position] = Tile;
}

float Tile::getTileCost()const
{
	return m_cost;
}

void Tile::setTileCost(const float cost)
{
	m_cost = cost;
	//TODO: Display const in label
	//format string to 1 decimal place
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << cost;
	const std::string const_string = stream.str();

	m_costLabel->setText(const_string);
	
}

void Tile::addLabels()
{
	auto offset = glm::vec2(Config::TILE_SIZE * 0.5f, Config::TILE_SIZE * 0.5f);
	m_costLabel = new Label("99.9", "Consolas", 12);
	m_costLabel->getTransform()->position = getTransform()->position + offset + glm::vec2(0.0f, -6.0f);
	getParent()->addChild(m_costLabel);
	m_costLabel->setEnabled(false);
	
	m_statusLabel = new Label("--", "Consolas", 12);
	m_statusLabel->getTransform()->position = getTransform()->position + offset+ glm::vec2(0.0f, 6.0f);
	getParent()->addChild(m_statusLabel);
	m_statusLabel->setEnabled(false);
}

void Tile::setLabelEnabled(const bool state)const
{
	m_costLabel->setEnabled(state);
	m_statusLabel->setEnabled(state);
}

glm::vec2 Tile::getGridpos()const
{
	return m_gridpos;
}

void Tile::setGridpos(float col,float row)
{
	m_gridpos = glm::vec2(col, row);
}
