#pragma once
#include <memory>
#include <string>

namespace centurion {
namespace tools {

class ApplicationPath;
typedef std::shared_ptr<ApplicationPath> ApplicationPath_sptr;
typedef std::unique_ptr<ApplicationPath> ApplicationPath_uptr;
typedef std::weak_ptr<ApplicationPath> ApplicationPath_wptr;

/**
\brief The ApplicationPath class represents the file path of the application
executable. It's useful for things such as locating resources.
\since 1.0.0
*/
class ApplicationPath final {
 private:
  char* path_cstr;
  std::string path_cpp;

 public:
  ApplicationPath();

  ~ApplicationPath();

  /**
  \brief Returns the absolute path of the application executable.
  \since 1.0.0
  */
  const std::string GetAbsolutePath() const noexcept;

  /**
  \brief Creates and returns a path based on the path of the application
  executable.
  \param path - the target path, relative to the application location.
  \since 1.0.0 Example: Application location:
  ".../MyProjects/HelloWorld/app.exe" Relative path: "resources/image.png"
  CreateRelativePath( *Relative path* ) =>
  ".../MyProjects/HelloWorld/resources/image.png"
  */
  const std::string CreateRelativePath(const std::string& path) const noexcept;

  /**
  \brief Returns a shared pointer that points to an ApplicationPath instance.
  \since 2.0.0
  */
  static ApplicationPath_sptr CreateShared();

  /**
  \brief Returns a unique pointer that points to an ApplicationPath instance.
  \since 2.0.0
  */
  static ApplicationPath_uptr CreateUnique();

  /**
  \brief Returns a weak pointer that points to an ApplicationPath instance.
  \since 2.0.0
  */
  static ApplicationPath_wptr CreateWeak();
};

}  // namespace tools
}  // namespace centurion