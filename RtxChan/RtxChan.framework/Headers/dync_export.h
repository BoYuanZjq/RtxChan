#ifndef __DYNC_EXPORT_H__
#define __DYNC_EXPORT_H__

#ifdef DYNC_EXPORT
#define DYNC_API _declspec(dllexport)
#elif DYNC_DLL
#define DYNC_API _declspec(dllimport)
#elif DYNC_POSIX
#define DYNC_API __attribute__ ((visibility ("default")))
#else
#define DYNC_API
#endif

#endif	// __DYNC_EXPORT_H__