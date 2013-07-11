#ifndef SFMLTEST_HPP
#define SFMLTEST_HPP


////////////////////////////////////////////////////////////
// Identify the operating system
////////////////////////////////////////////////////////////


#if defined(_WIN32) || defined(__WIN32__)
#define SFMLTEST_SYSTEM_WINDOWS
	#ifndef NOMINMAX
	#define NOMINMAX
	#endif

#elif defined(linux) || defined(__linux)
#define SFMLTEST_SYSTEM_LINUX

#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
#define SFMLTEST_SYSTEM_OSX

#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define SFMLTEST_SYSTEM_FREEBSD

#else
#error This operating system is not supported

#endif


////////////////////////////////////////////////////////////
// Import/export to a dynamic library
////////////////////////////////////////////////////////////


#if !defined(SFMLTEST_STATIC)
	#if defined(SFMLTEST_SYSTEM_WINDOWS) || defined(_MSC_VER) || defined(SFMLTEST_EXPORT)
	#define SFMLTEST_API __declspec(dllexport)
	#elif defined(SFMLTEST_SYSTEM_WINDOWS) || defined(_MSC_VER)
	#define SFMLTEST_API __declspec(dllimport)
	#elif !defined(SFMLTEST_SYSTEM_WINDOWS) && (__GNUC__ >= 4)
	#define SFMLTEST_API __attribute__ ((__visibility__ ("default")))
	#else
	#define SFMLTEST_API
	#endif

#else
#define SFMLTEST_API

#endif


////////////////////////////////////////////////////////////
// Library function
////////////////////////////////////////////////////////////


SFMLTEST_API void createSfmlWindow();


#endif // SFMLTEST_HPP
