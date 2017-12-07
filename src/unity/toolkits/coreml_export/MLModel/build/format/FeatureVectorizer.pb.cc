// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FeatureVectorizer.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "FeatureVectorizer.pb.h"

#include <algorithm>

#include <protobuf/stubs/common.h>
#include <protobuf/stubs/port.h>
#include <protobuf/stubs/once.h>
#include <protobuf/io/coded_stream.h>
#include <protobuf/wire_format_lite_inl.h>
#include <protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)

namespace CoreML {
namespace Specification {

void protobuf_ShutdownFile_FeatureVectorizer_2eproto() {
  FeatureVectorizer_default_instance_.Shutdown();
  FeatureVectorizer_InputColumn_default_instance_.Shutdown();
}

void protobuf_InitDefaults_FeatureVectorizer_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  FeatureVectorizer_default_instance_.DefaultConstruct();
  ::google::protobuf::internal::GetEmptyString();
  FeatureVectorizer_InputColumn_default_instance_.DefaultConstruct();
  FeatureVectorizer_default_instance_.get_mutable()->InitAsDefaultInstance();
  FeatureVectorizer_InputColumn_default_instance_.get_mutable()->InitAsDefaultInstance();
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_FeatureVectorizer_2eproto_once_);
void protobuf_InitDefaults_FeatureVectorizer_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_FeatureVectorizer_2eproto_once_,
                 &protobuf_InitDefaults_FeatureVectorizer_2eproto_impl);
}
void protobuf_AddDesc_FeatureVectorizer_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_FeatureVectorizer_2eproto();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_FeatureVectorizer_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_FeatureVectorizer_2eproto_once_);
void protobuf_AddDesc_FeatureVectorizer_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_FeatureVectorizer_2eproto_once_,
                 &protobuf_AddDesc_FeatureVectorizer_2eproto_impl);
}
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_FeatureVectorizer_2eproto {
  StaticDescriptorInitializer_FeatureVectorizer_2eproto() {
    protobuf_AddDesc_FeatureVectorizer_2eproto();
  }
} static_descriptor_initializer_FeatureVectorizer_2eproto_;
#endif  // GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD GOOGLE_ATTRIBUTE_NORETURN;
static void MergeFromFail(int line) {
  ::google::protobuf::internal::MergeFromFail(__FILE__, line);
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int FeatureVectorizer_InputColumn::kInputColumnFieldNumber;
const int FeatureVectorizer_InputColumn::kInputDimensionsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

FeatureVectorizer_InputColumn::FeatureVectorizer_InputColumn()
  : ::google::protobuf::MessageLite(), _arena_ptr_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_FeatureVectorizer_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:CoreML.Specification.FeatureVectorizer.InputColumn)
}

void FeatureVectorizer_InputColumn::InitAsDefaultInstance() {
}

FeatureVectorizer_InputColumn::FeatureVectorizer_InputColumn(const FeatureVectorizer_InputColumn& from)
  : ::google::protobuf::MessageLite(),
    _arena_ptr_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:CoreML.Specification.FeatureVectorizer.InputColumn)
}

void FeatureVectorizer_InputColumn::SharedCtor() {
  inputcolumn_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  inputdimensions_ = GOOGLE_ULONGLONG(0);
  _cached_size_ = 0;
}

FeatureVectorizer_InputColumn::~FeatureVectorizer_InputColumn() {
  // @@protoc_insertion_point(destructor:CoreML.Specification.FeatureVectorizer.InputColumn)
  SharedDtor();
}

void FeatureVectorizer_InputColumn::SharedDtor() {
  inputcolumn_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void FeatureVectorizer_InputColumn::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const FeatureVectorizer_InputColumn& FeatureVectorizer_InputColumn::default_instance() {
  protobuf_InitDefaults_FeatureVectorizer_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<FeatureVectorizer_InputColumn> FeatureVectorizer_InputColumn_default_instance_;

FeatureVectorizer_InputColumn* FeatureVectorizer_InputColumn::New(::google::protobuf::Arena* arena) const {
  FeatureVectorizer_InputColumn* n = new FeatureVectorizer_InputColumn;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void FeatureVectorizer_InputColumn::Clear() {
// @@protoc_insertion_point(message_clear_start:CoreML.Specification.FeatureVectorizer.InputColumn)
  inputcolumn_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  inputdimensions_ = GOOGLE_ULONGLONG(0);
}

bool FeatureVectorizer_InputColumn::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CoreML.Specification.FeatureVectorizer.InputColumn)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string inputColumn = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_inputcolumn()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->inputcolumn().data(), this->inputcolumn().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_inputDimensions;
        break;
      }

      // optional uint64 inputDimensions = 2;
      case 2: {
        if (tag == 16) {
         parse_inputDimensions:

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &inputdimensions_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:CoreML.Specification.FeatureVectorizer.InputColumn)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CoreML.Specification.FeatureVectorizer.InputColumn)
  return false;
#undef DO_
}

void FeatureVectorizer_InputColumn::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CoreML.Specification.FeatureVectorizer.InputColumn)
  // optional string inputColumn = 1;
  if (this->inputcolumn().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->inputcolumn().data(), this->inputcolumn().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->inputcolumn(), output);
  }

  // optional uint64 inputDimensions = 2;
  if (this->inputdimensions() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->inputdimensions(), output);
  }

  // @@protoc_insertion_point(serialize_end:CoreML.Specification.FeatureVectorizer.InputColumn)
}

size_t FeatureVectorizer_InputColumn::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CoreML.Specification.FeatureVectorizer.InputColumn)
  size_t total_size = 0;

  // optional string inputColumn = 1;
  if (this->inputcolumn().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->inputcolumn());
  }

  // optional uint64 inputDimensions = 2;
  if (this->inputdimensions() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->inputdimensions());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void FeatureVectorizer_InputColumn::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const FeatureVectorizer_InputColumn*>(&from));
}

void FeatureVectorizer_InputColumn::MergeFrom(const FeatureVectorizer_InputColumn& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CoreML.Specification.FeatureVectorizer.InputColumn)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void FeatureVectorizer_InputColumn::UnsafeMergeFrom(const FeatureVectorizer_InputColumn& from) {
  GOOGLE_DCHECK(&from != this);
  if (from.inputcolumn().size() > 0) {

    inputcolumn_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.inputcolumn_);
  }
  if (from.inputdimensions() != 0) {
    set_inputdimensions(from.inputdimensions());
  }
}

void FeatureVectorizer_InputColumn::CopyFrom(const FeatureVectorizer_InputColumn& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CoreML.Specification.FeatureVectorizer.InputColumn)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool FeatureVectorizer_InputColumn::IsInitialized() const {

  return true;
}

void FeatureVectorizer_InputColumn::Swap(FeatureVectorizer_InputColumn* other) {
  if (other == this) return;
  InternalSwap(other);
}
void FeatureVectorizer_InputColumn::InternalSwap(FeatureVectorizer_InputColumn* other) {
  inputcolumn_.Swap(&other->inputcolumn_);
  std::swap(inputdimensions_, other->inputdimensions_);
  _unknown_fields_.Swap(&other->_unknown_fields_);
  std::swap(_cached_size_, other->_cached_size_);
}

::std::string FeatureVectorizer_InputColumn::GetTypeName() const {
  return "CoreML.Specification.FeatureVectorizer.InputColumn";
}


// -------------------------------------------------------------------

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int FeatureVectorizer::kInputListFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

FeatureVectorizer::FeatureVectorizer()
  : ::google::protobuf::MessageLite(), _arena_ptr_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_FeatureVectorizer_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:CoreML.Specification.FeatureVectorizer)
}

void FeatureVectorizer::InitAsDefaultInstance() {
}

FeatureVectorizer::FeatureVectorizer(const FeatureVectorizer& from)
  : ::google::protobuf::MessageLite(),
    _arena_ptr_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:CoreML.Specification.FeatureVectorizer)
}

void FeatureVectorizer::SharedCtor() {
  _cached_size_ = 0;
}

FeatureVectorizer::~FeatureVectorizer() {
  // @@protoc_insertion_point(destructor:CoreML.Specification.FeatureVectorizer)
  SharedDtor();
}

void FeatureVectorizer::SharedDtor() {
}

void FeatureVectorizer::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const FeatureVectorizer& FeatureVectorizer::default_instance() {
  protobuf_InitDefaults_FeatureVectorizer_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<FeatureVectorizer> FeatureVectorizer_default_instance_;

FeatureVectorizer* FeatureVectorizer::New(::google::protobuf::Arena* arena) const {
  FeatureVectorizer* n = new FeatureVectorizer;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void FeatureVectorizer::Clear() {
// @@protoc_insertion_point(message_clear_start:CoreML.Specification.FeatureVectorizer)
  inputlist_.Clear();
}

bool FeatureVectorizer::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CoreML.Specification.FeatureVectorizer)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .CoreML.Specification.FeatureVectorizer.InputColumn inputList = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_inputList:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_inputlist()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_inputList;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:CoreML.Specification.FeatureVectorizer)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CoreML.Specification.FeatureVectorizer)
  return false;
#undef DO_
}

void FeatureVectorizer::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CoreML.Specification.FeatureVectorizer)
  // repeated .CoreML.Specification.FeatureVectorizer.InputColumn inputList = 1;
  for (unsigned int i = 0, n = this->inputlist_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->inputlist(i), output);
  }

  // @@protoc_insertion_point(serialize_end:CoreML.Specification.FeatureVectorizer)
}

size_t FeatureVectorizer::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CoreML.Specification.FeatureVectorizer)
  size_t total_size = 0;

  // repeated .CoreML.Specification.FeatureVectorizer.InputColumn inputList = 1;
  {
    unsigned int count = this->inputlist_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->inputlist(i));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void FeatureVectorizer::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const FeatureVectorizer*>(&from));
}

void FeatureVectorizer::MergeFrom(const FeatureVectorizer& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CoreML.Specification.FeatureVectorizer)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void FeatureVectorizer::UnsafeMergeFrom(const FeatureVectorizer& from) {
  GOOGLE_DCHECK(&from != this);
  inputlist_.MergeFrom(from.inputlist_);
}

void FeatureVectorizer::CopyFrom(const FeatureVectorizer& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CoreML.Specification.FeatureVectorizer)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool FeatureVectorizer::IsInitialized() const {

  return true;
}

void FeatureVectorizer::Swap(FeatureVectorizer* other) {
  if (other == this) return;
  InternalSwap(other);
}
void FeatureVectorizer::InternalSwap(FeatureVectorizer* other) {
  inputlist_.UnsafeArenaSwap(&other->inputlist_);
  _unknown_fields_.Swap(&other->_unknown_fields_);
  std::swap(_cached_size_, other->_cached_size_);
}

::std::string FeatureVectorizer::GetTypeName() const {
  return "CoreML.Specification.FeatureVectorizer";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// FeatureVectorizer_InputColumn

// optional string inputColumn = 1;
void FeatureVectorizer_InputColumn::clear_inputcolumn() {
  inputcolumn_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& FeatureVectorizer_InputColumn::inputcolumn() const {
  // @@protoc_insertion_point(field_get:CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn)
  return inputcolumn_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void FeatureVectorizer_InputColumn::set_inputcolumn(const ::std::string& value) {
  
  inputcolumn_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn)
}
void FeatureVectorizer_InputColumn::set_inputcolumn(const char* value) {
  
  inputcolumn_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn)
}
void FeatureVectorizer_InputColumn::set_inputcolumn(const char* value, size_t size) {
  
  inputcolumn_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn)
}
::std::string* FeatureVectorizer_InputColumn::mutable_inputcolumn() {
  
  // @@protoc_insertion_point(field_mutable:CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn)
  return inputcolumn_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* FeatureVectorizer_InputColumn::release_inputcolumn() {
  // @@protoc_insertion_point(field_release:CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn)
  
  return inputcolumn_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void FeatureVectorizer_InputColumn::set_allocated_inputcolumn(::std::string* inputcolumn) {
  if (inputcolumn != NULL) {
    
  } else {
    
  }
  inputcolumn_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), inputcolumn);
  // @@protoc_insertion_point(field_set_allocated:CoreML.Specification.FeatureVectorizer.InputColumn.inputColumn)
}

// optional uint64 inputDimensions = 2;
void FeatureVectorizer_InputColumn::clear_inputdimensions() {
  inputdimensions_ = GOOGLE_ULONGLONG(0);
}
::google::protobuf::uint64 FeatureVectorizer_InputColumn::inputdimensions() const {
  // @@protoc_insertion_point(field_get:CoreML.Specification.FeatureVectorizer.InputColumn.inputDimensions)
  return inputdimensions_;
}
void FeatureVectorizer_InputColumn::set_inputdimensions(::google::protobuf::uint64 value) {
  
  inputdimensions_ = value;
  // @@protoc_insertion_point(field_set:CoreML.Specification.FeatureVectorizer.InputColumn.inputDimensions)
}

inline const FeatureVectorizer_InputColumn* FeatureVectorizer_InputColumn::internal_default_instance() {
  return &FeatureVectorizer_InputColumn_default_instance_.get();
}
// -------------------------------------------------------------------

// FeatureVectorizer

// repeated .CoreML.Specification.FeatureVectorizer.InputColumn inputList = 1;
int FeatureVectorizer::inputlist_size() const {
  return inputlist_.size();
}
void FeatureVectorizer::clear_inputlist() {
  inputlist_.Clear();
}
const ::CoreML::Specification::FeatureVectorizer_InputColumn& FeatureVectorizer::inputlist(int index) const {
  // @@protoc_insertion_point(field_get:CoreML.Specification.FeatureVectorizer.inputList)
  return inputlist_.Get(index);
}
::CoreML::Specification::FeatureVectorizer_InputColumn* FeatureVectorizer::mutable_inputlist(int index) {
  // @@protoc_insertion_point(field_mutable:CoreML.Specification.FeatureVectorizer.inputList)
  return inputlist_.Mutable(index);
}
::CoreML::Specification::FeatureVectorizer_InputColumn* FeatureVectorizer::add_inputlist() {
  // @@protoc_insertion_point(field_add:CoreML.Specification.FeatureVectorizer.inputList)
  return inputlist_.Add();
}
::google::protobuf::RepeatedPtrField< ::CoreML::Specification::FeatureVectorizer_InputColumn >*
FeatureVectorizer::mutable_inputlist() {
  // @@protoc_insertion_point(field_mutable_list:CoreML.Specification.FeatureVectorizer.inputList)
  return &inputlist_;
}
const ::google::protobuf::RepeatedPtrField< ::CoreML::Specification::FeatureVectorizer_InputColumn >&
FeatureVectorizer::inputlist() const {
  // @@protoc_insertion_point(field_list:CoreML.Specification.FeatureVectorizer.inputList)
  return inputlist_;
}

inline const FeatureVectorizer* FeatureVectorizer::internal_default_instance() {
  return &FeatureVectorizer_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace Specification
}  // namespace CoreML

// @@protoc_insertion_point(global_scope)
