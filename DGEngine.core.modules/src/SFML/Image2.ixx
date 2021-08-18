export module dgengine.sfml.image2;

import sfml;

export namespace sf
{
	class Image2 : public Image
	{
	public:
		operator Texture() const
		{
			Texture tex;
			tex.loadFromImage(*this);
			return tex;
		}
	};
}
