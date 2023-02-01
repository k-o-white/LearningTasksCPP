// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: record.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_record_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_record_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_record_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_record_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_record_2eproto;
class Record;
struct RecordDefaultTypeInternal;
extern RecordDefaultTypeInternal _Record_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Record* Arena::CreateMaybeMessage<::Record>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Record final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Record) */ {
 public:
  inline Record() : Record(nullptr) {}
  ~Record() override;
  explicit PROTOBUF_CONSTEXPR Record(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Record(const Record& from);
  Record(Record&& from) noexcept
    : Record() {
    *this = ::std::move(from);
  }

  inline Record& operator=(const Record& from) {
    CopyFrom(from);
    return *this;
  }
  inline Record& operator=(Record&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Record& default_instance() {
    return *internal_default_instance();
  }
  static inline const Record* internal_default_instance() {
    return reinterpret_cast<const Record*>(
               &_Record_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Record& a, Record& b) {
    a.Swap(&b);
  }
  inline void Swap(Record* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Record* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Record* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Record>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Record& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Record& from) {
    Record::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Record* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Record";
  }
  protected:
  explicit Record(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAddressFieldNumber = 2,
    kNameFieldNumber = 3,
    kOccupationFieldNumber = 4,
    kFoundationYearFieldNumber = 1,
    kExternalEconomyFieldNumber = 5,
  };
  // required string address = 2;
  bool has_address() const;
  private:
  bool _internal_has_address() const;
  public:
  void clear_address();
  const std::string& address() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_address(ArgT0&& arg0, ArgT... args);
  std::string* mutable_address();
  PROTOBUF_NODISCARD std::string* release_address();
  void set_allocated_address(std::string* address);
  private:
  const std::string& _internal_address() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_address(const std::string& value);
  std::string* _internal_mutable_address();
  public:

  // required string name = 3;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // optional string occupation = 4;
  bool has_occupation() const;
  private:
  bool _internal_has_occupation() const;
  public:
  void clear_occupation();
  const std::string& occupation() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_occupation(ArgT0&& arg0, ArgT... args);
  std::string* mutable_occupation();
  PROTOBUF_NODISCARD std::string* release_occupation();
  void set_allocated_occupation(std::string* occupation);
  private:
  const std::string& _internal_occupation() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_occupation(const std::string& value);
  std::string* _internal_mutable_occupation();
  public:

  // required int32 foundation_year = 1;
  bool has_foundation_year() const;
  private:
  bool _internal_has_foundation_year() const;
  public:
  void clear_foundation_year();
  int32_t foundation_year() const;
  void set_foundation_year(int32_t value);
  private:
  int32_t _internal_foundation_year() const;
  void _internal_set_foundation_year(int32_t value);
  public:

  // optional bool external_economy = 5;
  bool has_external_economy() const;
  private:
  bool _internal_has_external_economy() const;
  public:
  void clear_external_economy();
  bool external_economy() const;
  void set_external_economy(bool value);
  private:
  bool _internal_external_economy() const;
  void _internal_set_external_economy(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Record)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr address_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr occupation_;
    int32_t foundation_year_;
    bool external_economy_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_record_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Record

// required int32 foundation_year = 1;
inline bool Record::_internal_has_foundation_year() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool Record::has_foundation_year() const {
  return _internal_has_foundation_year();
}
inline void Record::clear_foundation_year() {
  _impl_.foundation_year_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline int32_t Record::_internal_foundation_year() const {
  return _impl_.foundation_year_;
}
inline int32_t Record::foundation_year() const {
  // @@protoc_insertion_point(field_get:Record.foundation_year)
  return _internal_foundation_year();
}
inline void Record::_internal_set_foundation_year(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.foundation_year_ = value;
}
inline void Record::set_foundation_year(int32_t value) {
  _internal_set_foundation_year(value);
  // @@protoc_insertion_point(field_set:Record.foundation_year)
}

// required string address = 2;
inline bool Record::_internal_has_address() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Record::has_address() const {
  return _internal_has_address();
}
inline void Record::clear_address() {
  _impl_.address_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Record::address() const {
  // @@protoc_insertion_point(field_get:Record.address)
  return _internal_address();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_address(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.address_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.address)
}
inline std::string* Record::mutable_address() {
  std::string* _s = _internal_mutable_address();
  // @@protoc_insertion_point(field_mutable:Record.address)
  return _s;
}
inline const std::string& Record::_internal_address() const {
  return _impl_.address_.Get();
}
inline void Record::_internal_set_address(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.address_.Set(value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_address() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.address_.Mutable(GetArenaForAllocation());
}
inline std::string* Record::release_address() {
  // @@protoc_insertion_point(field_release:Record.address)
  if (!_internal_has_address()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.address_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.address_.IsDefault()) {
    _impl_.address_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Record::set_allocated_address(std::string* address) {
  if (address != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.address_.SetAllocated(address, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.address_.IsDefault()) {
    _impl_.address_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Record.address)
}

// required string name = 3;
inline bool Record::_internal_has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Record::has_name() const {
  return _internal_has_name();
}
inline void Record::clear_name() {
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Record::name() const {
  // @@protoc_insertion_point(field_get:Record.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_name(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000002u;
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.name)
}
inline std::string* Record::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Record.name)
  return _s;
}
inline const std::string& Record::_internal_name() const {
  return _impl_.name_.Get();
}
inline void Record::_internal_set_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_name() {
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* Record::release_name() {
  // @@protoc_insertion_point(field_release:Record.name)
  if (!_internal_has_name()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* p = _impl_.name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Record::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Record.name)
}

// optional string occupation = 4;
inline bool Record::_internal_has_occupation() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool Record::has_occupation() const {
  return _internal_has_occupation();
}
inline void Record::clear_occupation() {
  _impl_.occupation_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& Record::occupation() const {
  // @@protoc_insertion_point(field_get:Record.occupation)
  return _internal_occupation();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_occupation(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000004u;
 _impl_.occupation_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.occupation)
}
inline std::string* Record::mutable_occupation() {
  std::string* _s = _internal_mutable_occupation();
  // @@protoc_insertion_point(field_mutable:Record.occupation)
  return _s;
}
inline const std::string& Record::_internal_occupation() const {
  return _impl_.occupation_.Get();
}
inline void Record::_internal_set_occupation(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.occupation_.Set(value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_occupation() {
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.occupation_.Mutable(GetArenaForAllocation());
}
inline std::string* Record::release_occupation() {
  // @@protoc_insertion_point(field_release:Record.occupation)
  if (!_internal_has_occupation()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000004u;
  auto* p = _impl_.occupation_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.occupation_.IsDefault()) {
    _impl_.occupation_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Record::set_allocated_occupation(std::string* occupation) {
  if (occupation != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.occupation_.SetAllocated(occupation, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.occupation_.IsDefault()) {
    _impl_.occupation_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Record.occupation)
}

// optional bool external_economy = 5;
inline bool Record::_internal_has_external_economy() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool Record::has_external_economy() const {
  return _internal_has_external_economy();
}
inline void Record::clear_external_economy() {
  _impl_.external_economy_ = false;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline bool Record::_internal_external_economy() const {
  return _impl_.external_economy_;
}
inline bool Record::external_economy() const {
  // @@protoc_insertion_point(field_get:Record.external_economy)
  return _internal_external_economy();
}
inline void Record::_internal_set_external_economy(bool value) {
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.external_economy_ = value;
}
inline void Record::set_external_economy(bool value) {
  _internal_set_external_economy(value);
  // @@protoc_insertion_point(field_set:Record.external_economy)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_record_2eproto
