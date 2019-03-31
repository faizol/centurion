#pragma once
#include <SDL_rect.h>
#include "dimensioned.h"
#include "point.h"
#include "positionable.h"

namespace centurion {
namespace geo {

/**
\brief The Rectangle class quite simply represents a rectangle.
*/
class Rectangle : public centurion::geo::Positionable,
                  public centurion::geo::Dimensioned {
 private:
  SDL_Rect rect;

  bool Contains(SDL_Point point) const;

 public:
  /**
  \param x - the initial x-coordinate of the rectangle.
  \param y - the initial y-coordinate of the rectangle.
  \param w - the width of the rectangle.
  \param h - the height of the rectangle.
  */
  Rectangle(int x, int y, int w, int h);

  /**
  \param w - the width of the rectangle.
  \param h - the height of the rectangle.
  */
  Rectangle(int w, int h);

  ~Rectangle() override;

  /**
  \brief Assigns the location of this rectangle.
  \param x - the new x-coordinate.
  \param y - the new y-coordinate.
  */
  void SetLocation(int x, int y) override;

  /**
  \brief Assigns the x-coordinate of this rectangle.
  \param x - the new x-coordinate.
  */
  void SetX(int x) override;

  /**
  \brief Assigns the y-coordinate of this rectangle.
  \param y - the new y-coordinate.
  */
  void SetY(int y) override;

  /**
  \brief Indicates whether or not this rectangle intersects another rectangle.
  Returns true if the supplied rectangle intersects this rectangle, returns
  false otherwise. \param rect - the rectangle that will be checked with this
  rectangle.
  */
  bool Intersects(const centurion::geo::Rectangle& rect) const;

  /**
  \brief Indicates whether or not this rectangle contains the specified point.
  Returns true if the point is contained in this rectangle, returns false
  otherwise. \param x - the x-coordinate of the point to check. \param y - the
  y-coordinate of the point to check.
  */
  bool Contains(int x, int y) const;

  /**
  \brief Indicates whether or not this rectangle contains the specified point.
  Returns true if the point is contained in this rectangle, returns false
  otherwise. \param point - the point that will be checked.
  */
  bool Contains(const centurion::geo::Point& point) const;

  /**
  \brief Returns the x-coordinate of this rectangle.
  */
  int GetX() const override { return rect.x; };

  /**
  \brief Returns the y-coordinate of this rectangle.
  */
  int GetY() const override { return rect.y; };

  /**
  \brief Returns the width of this rectangle.
  */
  int GetWidth() const override { return rect.w; };

  /**
  \brief Returns the height of this rectangle.
  */
  int GetHeight() const override { return rect.h; };

  /**
  \brief Creates and returns an SDL_Rect that represents this rectangle.
  */
  SDL_Rect GetSDLVersion() const { return rect; };
};

}  // namespace geo
}  // namespace centurion