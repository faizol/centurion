#pragma once
#include <memory>
#include <vector>
#include "ctn_event.h"
#include "ctn_key_stroke.h"

namespace centurion {
namespace events {

class KeyStrokeComposite;
typedef std::shared_ptr<KeyStrokeComposite> KeyStrokeComposite_sptr;
typedef std::unique_ptr<KeyStrokeComposite> KeyStrokeComposite_uptr;
typedef std::weak_ptr<KeyStrokeComposite> KeyStrokeComposite_wptr;

/**
* DEPRECATED *
\brief The KeyStrokeComposite is a convenience class designed to hold multiple
KeyStroke instances.
\since 1.0.0
*/
class KeyStrokeComposite final {
 private:
  std::vector<KeyStroke_sptr> keyStrokes;

 public:
  KeyStrokeComposite();

  ~KeyStrokeComposite();

  /**
  \brief Updates all held KeyStrokes with the supplied Event.
  \param event - the Event that will be dispatched to all KeyStroke instances.
  \since 1.0.0
  */
  void Update(const Event& event);

  /**
  \brief Adds a KeyStroke instance to the composite.
  \param keyStroke - the KeyStroke instance that will be added.
  \since 1.0.0
  */
  void AddKeyStroke(KeyStroke_sptr keyStroke);

  /**
  \brief Clears the composite of all KeyStroke instances.
  \since 1.0.0
  */
  void Clear() noexcept;

  /**
  \brief Returns a shared pointer that points to a KeyStrokeComposite instance.
  \since 1.1.0
  */
  static KeyStrokeComposite_sptr CreateShared();

  /**
  \brief Returns a unique pointer that points to a KeyStrokeComposite instance.
  \since 1.1.0
  */
  static KeyStrokeComposite_uptr CreateUnique();

  /**
  \brief Returns a weak pointer that points to a KeyStrokeComposite instance.
  \since 1.1.0
  */
  static KeyStrokeComposite_wptr CreateWeak();
};

}  // namespace events
}  // namespace centurion