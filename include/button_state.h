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

/**
 * @brief Provides the @link centurion::ButtonState @endlink enum.
 *
 * @file button_state.h
 * @author Albin Johansson
 * @date 2019-2020
 * @copyright MIT License
 */

#ifndef CENTURION_BUTTON_STATE_HEADER
#define CENTURION_BUTTON_STATE_HEADER

#include <SDL_events.h>

namespace centurion {

/**
 * @enum ButtonState
 *
 * @brief Represents the two possible states for a button.
 * @details Corresponds to the `SDL_RELEASED` and `SDL_PRESSED` macros.
 *
 * @headerfile button_state.h
 * @since 3.1.0
 */
enum class ButtonState {
  Released = SDL_RELEASED, /**< Button is released. Corresponds to
                            * `SDL_RELEASED`.*/
  Pressed = SDL_PRESSED    /**< Button is pressed. Corresponds to
                            * `SDL_PRESSED`.*/
};

}  // namespace centurion

#endif  // CENTURION_BUTTON_STATE_HEADER