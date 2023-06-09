module;

#include <algorithm>

module Jet.Parser.ModuleParse;

namespace jet::parser
{

auto FileLines::line_at(usize byte_index) const -> usize
{
  auto it = std::upper_bound(line_starts.begin(), line_starts.end(), byte_index);
  return std::distance(line_starts.begin(), it);
}

auto FileLines::column_at(usize byte_index) const -> usize
{
  auto col = usize(0);
  auto curr = line_starts[line_at(byte_index)];
  while (curr != byte_index) {
    curr = next_utf8_pos(content, curr);
    ++col;
  }
  return col;
}

auto FileLines::push_line_start(usize byte_index) -> void
{
  // Ensure no backtracking
  if (!line_starts.empty() && line_starts.back() >= byte_index) {
    return;
  }

  line_starts.push_back(byte_index);
}

}