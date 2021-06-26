#include <SFML/Graphics.hpp>

using namespace sf;

class Block 
{
public:
	Block(int x, int y, int z, Sprite sp);
	void Draw(RenderWindow& window);
private:
	int x, y, z;
	Sprite sp;
};

Block::Block(int x, int y, int z, Sprite sp)
{
	this->x = x*128; this->y = y*128; this->z = z;
	this->sp = sp;
	sp.scale(z, z);
}
void Block::Draw(RenderWindow& window) 
{
	sp.setTextureRect(IntRect(x%2000, x % 2000, 128, 128));
	sp.setPosition(x, y);
	window.draw(sp);
}

int main() 
{
	Texture GroundTexture;
	Texture DirtTexture;
	Texture StoneTexture;

	GroundTexture.loadFromFile("../../../../Desktop/grass-1.jpg");
	DirtTexture.loadFromFile("../../../../Desktop/dirt.jpg");
	StoneTexture.loadFromFile("../../../../Desktop/stone.jpg");

	Sprite Ground(GroundTexture);
	Sprite Dirt(DirtTexture);
	Sprite Stone(StoneTexture);

	Block bl1 = Block(1, 1, 4, Ground);
	Block bl2 = Block(0, 1, 4, Dirt);
	Block bl3 = Block(2, 1, 4, Stone);


	RenderWindow window(VideoMode(800, 600), "minecraft2D");

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed) 
			{
				window.close();
			}
		}
		window.clear();
		bl1.Draw(window);
		bl2.Draw(window);
		bl3.Draw(window);
		window.display();
	}
}