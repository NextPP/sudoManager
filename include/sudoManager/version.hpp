#ifndef SUDOMANAGER_VERSION_HPP
#define SUDOMANAGER_VERSION_HPP

#define SM_VERSION_MAJOR 0
#define SM_VERSION_MINOR 0
#define SM_VERSION_PATCH 1

#define SM_STR_HELPER(x) #x
#define SM_STR(x) SM_STR_HELPER(x)

#define SM_VERSION                                                   \
  (SM_STR(SM_VERSION_MAJOR) "." SM_STR(SM_VERSION_MINOR) "." SM_STR( \
      SM_VERSION_PATCH))

#endif  // SUDOMANAGER_VERSION_HPP
