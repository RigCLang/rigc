module;

#include <variant>

export module Jet.Compiler.BuildProcess;

export import Jet.Compiler.BuildState;
export import Jet.Compiler.Settings;

export import Jet.Comp.Foundation;
using namespace jet::comp::foundation;

export namespace jet::compiler
{

/// Describes what went wrong with a build process.
struct BuildError
{
  int    exit_code = 1;
  String details;
};

using BuildResult = Result<std::monostate, BuildError>;

/// Starts a build process, obtaining settings from the program arguments.
///
/// @note The build state is not exposed. To get access to it, you have to
/// construct it yourself and use @c begin_build() function.
[[nodiscard]]
auto run_build(ProgramArgs const& args) -> BuildResult;

/// Starts a build process given a preconstructed build state.
///
/// @note Calling this function is only valid if @c BuildState::can_start()
/// evaluates to @c true.
[[nodiscard]]
auto begin_build(BuildState& build_state) -> BuildResult;

} // namespace jet::compiler