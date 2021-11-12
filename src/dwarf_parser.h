#pragma once

#include "types.h"

#include <memory>
#include <string>
#include <vector>

#ifdef HAVE_LIBDW
#include <elfutils/libdwfl.h>
#include <optional>

namespace bpftrace {

class BPFtrace;

class Dwarf
{
public:
  virtual ~Dwarf();

  static std::unique_ptr<Dwarf> GetFromBinary(const std::string &file_path);

  std::vector<std::string> get_function_params(
      const std::string &function) const;

  ProbeArgs resolve_args(const std::string &function);

private:
  explicit Dwarf(const std::string &file_path);

  std::vector<Dwarf_Die> function_param_dies(const std::string &function) const;

  std::optional<Dwarf_Die> get_func_die(const std::string &function) const;

  std::string get_type_name(Dwarf_Die &type_die) const;

  SizedType get_stype(Dwarf_Die &type_die) const;

  Dwfl *dwfl = nullptr;
  Dwfl_Callbacks callbacks;

  std::string file_path_;
};

} // namespace bpftrace

#else // HAVE_LIBDW

namespace bpftrace {

class Dwarf
{
public:
  static std::unique_ptr<Dwarf> GetFromBinary(const std::string &file_path_
                                              __attribute__((unused)));

  std::vector<std::string> get_function_params(const std::string &function
                                               __attribute__((unused))) const
  {
    return {};
  }

  ProbeArgs resolve_args(const std::string &function __attribute__((unused)))
  {
    return {};
  }
};

} // namespace bpftrace

#endif // HAVE_LIBDW
