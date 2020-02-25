#include "pixel_format.h"

#include <catch.hpp>

using namespace centurion::video;

TEST_CASE("PixelFormat enum values", "[PixelFormat]")
{
  SECTION("CTN left and SDL right")
  {
    CHECK(PixelFormat::Unknown == SDL_PIXELFORMAT_UNKNOWN);
    CHECK(PixelFormat::Index1LSB == SDL_PIXELFORMAT_INDEX1LSB);
    CHECK(PixelFormat::Index1MSB == SDL_PIXELFORMAT_INDEX1MSB);
    CHECK(PixelFormat::Index4LSB == SDL_PIXELFORMAT_INDEX4LSB);
    CHECK(PixelFormat::Index4MSB == SDL_PIXELFORMAT_INDEX4MSB);
    CHECK(PixelFormat::Index8 == SDL_PIXELFORMAT_INDEX8);

    CHECK(PixelFormat::RGB332 == SDL_PIXELFORMAT_RGB332);
    CHECK(PixelFormat::RGB444 == SDL_PIXELFORMAT_RGB444);
    CHECK(PixelFormat::RGB555 == SDL_PIXELFORMAT_RGB555);
    CHECK(PixelFormat::BGR555 == SDL_PIXELFORMAT_BGR555);

    CHECK(PixelFormat::ARGB4444 == SDL_PIXELFORMAT_ARGB4444);
    CHECK(PixelFormat::RGBA4444 == SDL_PIXELFORMAT_RGBA4444);
    CHECK(PixelFormat::ABGR4444 == SDL_PIXELFORMAT_ABGR4444);
    CHECK(PixelFormat::BGRA4444 == SDL_PIXELFORMAT_BGRA4444);

    CHECK(PixelFormat::ARGB1555 == SDL_PIXELFORMAT_ARGB1555);
    CHECK(PixelFormat::RGBA5551 == SDL_PIXELFORMAT_RGBA5551);
    CHECK(PixelFormat::ABGR1555 == SDL_PIXELFORMAT_ABGR1555);
    CHECK(PixelFormat::BGRA5551 == SDL_PIXELFORMAT_BGRA5551);

    CHECK(PixelFormat::RGB565 == SDL_PIXELFORMAT_RGB565);
    CHECK(PixelFormat::BGR565 == SDL_PIXELFORMAT_BGR565);

    CHECK(PixelFormat::RGB24 == SDL_PIXELFORMAT_RGB24);
    CHECK(PixelFormat::BGR24 == SDL_PIXELFORMAT_BGR24);

    CHECK(PixelFormat::RGB888 == SDL_PIXELFORMAT_RGB888);
    CHECK(PixelFormat::RGBX8888 == SDL_PIXELFORMAT_RGBX8888);
    CHECK(PixelFormat::BGR888 == SDL_PIXELFORMAT_BGR888);
    CHECK(PixelFormat::BGRX8888 == SDL_PIXELFORMAT_BGRX8888);

    CHECK(PixelFormat::ARGB8888 == SDL_PIXELFORMAT_ARGB8888);
    CHECK(PixelFormat::RGBA8888 == SDL_PIXELFORMAT_RGBA8888);
    CHECK(PixelFormat::ABGR8888 == SDL_PIXELFORMAT_ABGR8888);
    CHECK(PixelFormat::BGRA8888 == SDL_PIXELFORMAT_BGRA8888);

    CHECK(PixelFormat::ARGB2101010 == SDL_PIXELFORMAT_ARGB2101010);

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    CHECK(PixelFormat::RGBA32 == SDL_PIXELFORMAT_RGBA8888);
    CHECK(PixelFormat::ARGB32 == SDL_PIXELFORMAT_ARGB8888);
    CHECK(PixelFormat::BGRA32 == SDL_PIXELFORMAT_BGRA8888);
    CHECK(PixelFormat::ABGR32 == SDL_PIXELFORMAT_ABGR8888);
#else
    CHECK(PixelFormat::RGBA32 == SDL_PIXELFORMAT_ABGR8888);
    CHECK(PixelFormat::ARGB32 == SDL_PIXELFORMAT_BGRA8888);
    CHECK(PixelFormat::BGRA32 == SDL_PIXELFORMAT_ARGB8888);
    CHECK(PixelFormat::ABGR32 == SDL_PIXELFORMAT_RGBA8888);
#endif

    CHECK(PixelFormat::YV12 == SDL_PIXELFORMAT_YV12);
    CHECK(PixelFormat::IYUV == SDL_PIXELFORMAT_IYUV);
    CHECK(PixelFormat::YUY2 == SDL_PIXELFORMAT_YUY2);
    CHECK(PixelFormat::UYVY == SDL_PIXELFORMAT_UYVY);
    CHECK(PixelFormat::YVYU == SDL_PIXELFORMAT_YVYU);
    CHECK(PixelFormat::NV12 == SDL_PIXELFORMAT_NV12);
    CHECK(PixelFormat::NV21 == SDL_PIXELFORMAT_NV21);
    CHECK(PixelFormat::ExternalOES == SDL_PIXELFORMAT_EXTERNAL_OES);
  }

  SECTION("CTN right and SDL left")
  {
    CHECK(SDL_PIXELFORMAT_UNKNOWN == PixelFormat::Unknown);
    CHECK(SDL_PIXELFORMAT_INDEX1LSB == PixelFormat::Index1LSB);
    CHECK(SDL_PIXELFORMAT_INDEX1MSB == PixelFormat::Index1MSB);
    CHECK(SDL_PIXELFORMAT_INDEX4LSB == PixelFormat::Index4LSB);
    CHECK(SDL_PIXELFORMAT_INDEX4MSB == PixelFormat::Index4MSB);
    CHECK(SDL_PIXELFORMAT_INDEX8 == PixelFormat::Index8);

    CHECK(SDL_PIXELFORMAT_RGB332 == PixelFormat::RGB332);
    CHECK(SDL_PIXELFORMAT_RGB444 == PixelFormat::RGB444);
    CHECK(SDL_PIXELFORMAT_RGB555 == PixelFormat::RGB555);
    CHECK(SDL_PIXELFORMAT_BGR555 == PixelFormat::BGR555);

    CHECK(SDL_PIXELFORMAT_ARGB4444 == PixelFormat::ARGB4444);
    CHECK(SDL_PIXELFORMAT_RGBA4444 == PixelFormat::RGBA4444);
    CHECK(SDL_PIXELFORMAT_ABGR4444 == PixelFormat::ABGR4444);
    CHECK(SDL_PIXELFORMAT_BGRA4444 == PixelFormat::BGRA4444);

    CHECK(SDL_PIXELFORMAT_ARGB1555 == PixelFormat::ARGB1555);
    CHECK(SDL_PIXELFORMAT_RGBA5551 == PixelFormat::RGBA5551);
    CHECK(SDL_PIXELFORMAT_ABGR1555 == PixelFormat::ABGR1555);
    CHECK(SDL_PIXELFORMAT_BGRA5551 == PixelFormat::BGRA5551);

    CHECK(SDL_PIXELFORMAT_RGB565 == PixelFormat::RGB565);
    CHECK(SDL_PIXELFORMAT_BGR565 == PixelFormat::BGR565);

    CHECK(SDL_PIXELFORMAT_RGB24 == PixelFormat::RGB24);
    CHECK(SDL_PIXELFORMAT_BGR24 == PixelFormat::BGR24);

    CHECK(SDL_PIXELFORMAT_RGB888 == PixelFormat::RGB888);
    CHECK(SDL_PIXELFORMAT_RGBX8888 == PixelFormat::RGBX8888);
    CHECK(SDL_PIXELFORMAT_BGR888 == PixelFormat::BGR888);
    CHECK(SDL_PIXELFORMAT_BGRX8888 == PixelFormat::BGRX8888);

    CHECK(SDL_PIXELFORMAT_ARGB8888 == PixelFormat::ARGB8888);
    CHECK(SDL_PIXELFORMAT_RGBA8888 == PixelFormat::RGBA8888);
    CHECK(SDL_PIXELFORMAT_ABGR8888 == PixelFormat::ABGR8888);
    CHECK(SDL_PIXELFORMAT_BGRA8888 == PixelFormat::BGRA8888);

    CHECK(SDL_PIXELFORMAT_ARGB2101010 == PixelFormat::ARGB2101010);

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    CHECK(SDL_PIXELFORMAT_RGBA8888 == PixelFormat::RGBA32);
    CHECK(SDL_PIXELFORMAT_ARGB8888 == PixelFormat::ARGB32);
    CHECK(SDL_PIXELFORMAT_BGRA8888 == PixelFormat::BGRA32);
    CHECK(SDL_PIXELFORMAT_ABGR8888 == PixelFormat::ABGR32);
#else
    CHECK(SDL_PIXELFORMAT_ABGR8888 == PixelFormat::RGBA32);
    CHECK(SDL_PIXELFORMAT_BGRA8888 == PixelFormat::ARGB32);
    CHECK(SDL_PIXELFORMAT_ARGB8888 == PixelFormat::BGRA32);
    CHECK(SDL_PIXELFORMAT_RGBA8888 == PixelFormat::ABGR32);
#endif

    CHECK(SDL_PIXELFORMAT_YV12 == PixelFormat::YV12);
    CHECK(SDL_PIXELFORMAT_IYUV == PixelFormat::IYUV);
    CHECK(SDL_PIXELFORMAT_YUY2 == PixelFormat::YUY2);
    CHECK(SDL_PIXELFORMAT_UYVY == PixelFormat::UYVY);
    CHECK(SDL_PIXELFORMAT_YVYU == PixelFormat::YVYU);
    CHECK(SDL_PIXELFORMAT_NV12 == PixelFormat::NV12);
    CHECK(SDL_PIXELFORMAT_NV21 == PixelFormat::NV21);
    CHECK(SDL_PIXELFORMAT_EXTERNAL_OES == PixelFormat::ExternalOES);
  }

  CHECK(PixelFormat::YV12 != SDL_PIXELFORMAT_BGR555);
  CHECK(SDL_PIXELFORMAT_INDEX4LSB != PixelFormat::ABGR8888);
}