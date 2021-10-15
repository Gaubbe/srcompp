#ifdef SRCOMPP_WIN
#ifdef SRCOMPP_SHARED
#ifdef SRCOMPP_EXPORT
#define SRCOMPP_API __declspec(dllexport)
#else
#define SRCOMPP_API __declspec(dllimport)
#endif
#else
#define SRCOMPP_API
#endif
#else
#define SRCOMPP_API
#endif