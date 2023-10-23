#pragma once


#if EGG_DEBUG==2
	#define EGG_ERROR(x) std::cout <<x<<std::endl;
	#define EGG_LOG(x) std::cout <<x<<std::endl;
#elif EGG_DEBUG==1
	#define EGG_ERROR(x) std::cout <<x<<std::endl;
	#define EGG_LOG(x)
#else
	#define EGG_ERROR(x)
	#define EGG_LOG(x)
#endif

#ifdef EGG_MSCPP
	#ifdef EGG_LIB
		#define EGG_API __declspec(dllexport)
	#else
		#define EGG_API __declspec(dllimport)
	#endif
#else
	#define EGG_API
#endif

#define EGG_APPLICATION_START(ClassName) \
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}