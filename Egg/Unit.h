#pragma once

#include"Utilities.h"
#include"Picture.h"

namespace egg
{
	class EGG_API Unit
	{
	public:
		Unit(const std::string& image, int x, int y);
		Unit(std::string&& image, int x, int y);

		int GetWidth() const;
		int GetHeight() const;

		int GetXCoord() const;
		int GetYCoord() const;
		void SetCoords(int x, int y);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);

	private:
		Picture mImage;
		int mXPosition;
		int mYPosition;

		template<typename T> friend class EggApp;
		friend EGG_API bool UnitsOverlap(const Unit& a, const Unit& b);
	};

	EGG_API bool UnitsOverlap(const Unit& a, const Unit& b);
}