#pragma once

#include"pch.h"
#include"Utilities.h"
#include"PictureImplementation.h"


namespace egg
{
	class EGG_API Picture
	{
	public:

		Picture(const std::string& pictureFile);
		void Bind();
		int GetWidth();
		int GetHeight();

	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}