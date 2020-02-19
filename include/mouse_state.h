/*
 * MIT License
 *
 * Copyright (c) 2019-2020 Albin Johansson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef CENTURION_MOUSE_STATE_HEADER
#define CENTURION_MOUSE_STATE_HEADER

#include <memory>
#include <type_traits>

#include "centurion_api.h"
#include "window_listener.h"

namespace centurion {

/**
 * The MouseState class provides information about the mouse state, which is an
 * alternative to dealing with mouse events. This class implements the
 * IWindowListener interface. Important note! If you register a MouseState
 * instance as a window listener, you'll need to set the logical size of the
 * window manually, otherwise you'll end up with unexpected behaviour.
 *
 * @see IWindowListener
 * @since 3.0.0
 */
class MouseState final : public video::IWindowListener {
 private:
  int mouseX = 0;
  int mouseY = 0;
  int oldX = 0;
  int oldY = 0;

  int logicalWidth = 1;
  int logicalHeight = 1;
  int windowWidth = 1;
  int windowHeight = 1;

  bool leftPressed = false;
  bool rightPressed = false;
  bool prevLeftPressed = false;
  bool prevRightPressed = false;

 public:
  /**
   * @since 3.0.0
   */
  CENTURION_API MouseState() noexcept;

  CENTURION_API ~MouseState() noexcept override;

  /**
   * Creates and returns a unique pointer to a MouseState instance.
   *
   * @return a unique pointer to a MouseState instance.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API static std::unique_ptr<MouseState> unique();

  /**
   * Creates and returns a shared pointer to a MouseState instance.
   *
   * @return a shared pointer to a MouseState instance.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API static std::shared_ptr<MouseState> shared();

  CENTURION_API void window_updated(
      const video::Window& window) noexcept override;

  /**
   * Updates the mouse state.
   *
   * @since 3.0.0
   */
  CENTURION_API void update() noexcept;

  /**
   * Resets the screen and logical dimensions of the mouse state instance.
   *
   * @since 3.0.0
   */
  CENTURION_API void reset() noexcept;

  /**
   * Sets the logical width that will be used to determine the mouse position.
   * This method will use the default logical width when the supplied value is
   * <= 0.
   *
   * @param logicalWidth the logical width that will be used to determine the
   * mouse position.
   * @since 3.0.0
   */
  CENTURION_API void set_logical_width(int logicalWidth) noexcept;

  /**
   * Sets the logical height that will be used to determine the mouse position.
   * This method will use the default logical height when the supplied value is
   * <= 0.
   *
   * @param logicalHeight the logical height that will be used to determine the
   * mouse position.
   * @since 3.0.0
   */
  CENTURION_API void set_logical_height(int logicalHeight) noexcept;

  /**
   * Sets the window width that the mouse state instance will use when
   * calculating the mouse position. This method will use the default window
   * width when the supplied value is <= 0.
   *
   * @param windowWidth the width of the screen.
   * @since 3.0.0
   */
  CENTURION_API void set_window_width(int windowWidth) noexcept;

  /**
   * Sets the window height that the mouse state instance will use when
   * calculating the mouse position. This method will use the default window
   * height when the supplied value is <= 0.
   *
   * @param windowHeight the height of the screen.
   * @since 3.0.0
   */
  CENTURION_API void set_window_height(int windowHeight) noexcept;

  /**
   * Returns the x-coordinate of the mouse.
   *
   * @return the x-coordinate of the mouse.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API int get_mouse_x() const noexcept;

  /**
   * Returns the y-coordinate of the mouse.
   *
   * @return the y-coordinate of the mouse.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API int get_mouse_y() const noexcept;

  /**
   * Returns the window width used by the mouse state instance.
   *
   * @return the window width used by the mouse state instance, 1 is used by
   * default.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API int get_window_width() const noexcept;

  /**
   * Returns the window height used by the mouse state instance.
   *
   * @return the window height used by the mouse state instance, 1 is used by
   * default.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API int get_window_height() const noexcept;

  /**
   * Returns the logical width used by the mouse state instance.
   *
   * @return the logical width used by the mouse state instance, 1 is used by
   * default.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API int get_logical_width() const noexcept;

  /**
   * Returns the logical height used by the mouse state instance.
   *
   * @return the logical height used by the mouse state instance, 1 is used by
   * default.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API int get_logical_height() const noexcept;

  /**
   * Indicates whether or not the left mouse button is currently pressed.
   *
   * @return true if the left mouse button is pressed; false otherwise.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API bool is_left_button_pressed() const noexcept;

  /**
   * Indicates whether or not the right mouse button is currently pressed.
   *
   * @return true if the right mouse button is pressed; false otherwise.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API bool is_right_button_pressed() const noexcept;

  /**
   * Indicates whether or not the left mouse button was released.
   *
   * @return true if the left mouse button was released; false otherwise.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API bool was_left_button_released() const noexcept;

  /**
   * Indicates whether or not the right mouse button was released.
   *
   * @return true if the right mouse button was released; false otherwise.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API bool was_right_button_released() const noexcept;

  /**
   * Indicates whether or not the mouse was moved.
   *
   * @return true if the mouse was moved; false otherwise.
   * @since 3.0.0
   */
  CENTURION_NODISCARD
  CENTURION_API bool was_mouse_moved() const noexcept;
};

#ifdef CENTURION_HAS_IS_FINAL_TYPE_TRAIT
static_assert(std::is_final<MouseState>::value, "MouseState isn't final!");
#endif

static_assert(std::is_nothrow_move_constructible<MouseState>::value,
              "MouseState isn't nothrow move constructible!");

static_assert(std::is_nothrow_move_assignable<MouseState>::value,
              "MouseState isn't nothrow move assignable!");

static_assert(std::is_nothrow_copy_constructible<MouseState>::value,
              "MouseState isn't nothrow copy constructible!");

static_assert(std::is_nothrow_copy_assignable<MouseState>::value,
              "MouseState isn't nothrow copy assignable!");

static_assert(std::is_base_of<video::IWindowListener, MouseState>::value,
              "MouseState isn't a subclass of IWindowListener!");

}  // namespace centurion

#ifdef CENTURION_HEADER_ONLY
#include "mouse_state.cpp"
#endif

#endif  // CENTURION_MOUSE_STATE_HEADER