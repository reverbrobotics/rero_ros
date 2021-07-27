// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: text_to_speech.proto

#include "text_to_speech.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace rero {
constexpr TTSRequest::TTSRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : text_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct TTSRequestDefaultTypeInternal {
  constexpr TTSRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~TTSRequestDefaultTypeInternal() {}
  union {
    TTSRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT TTSRequestDefaultTypeInternal _TTSRequest_default_instance_;
constexpr TTSResponse::TTSResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : status_(false){}
struct TTSResponseDefaultTypeInternal {
  constexpr TTSResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~TTSResponseDefaultTypeInternal() {}
  union {
    TTSResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT TTSResponseDefaultTypeInternal _TTSResponse_default_instance_;
}  // namespace rero
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_text_5fto_5fspeech_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_text_5fto_5fspeech_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_text_5fto_5fspeech_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_text_5fto_5fspeech_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rero::TTSRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rero::TTSRequest, text_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rero::TTSResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rero::TTSResponse, status_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::rero::TTSRequest)},
  { 6, -1, sizeof(::rero::TTSResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::rero::_TTSRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::rero::_TTSResponse_default_instance_),
};

const char descriptor_table_protodef_text_5fto_5fspeech_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\024text_to_speech.proto\022\004rero\"\032\n\nTTSReque"
  "st\022\014\n\004text\030\001 \001(\t\"\035\n\013TTSResponse\022\016\n\006statu"
  "s\030\001 \001(\0102<\n\014TextToSpeech\022,\n\003TTS\022\020.rero.TT"
  "SRequest\032\021.rero.TTSResponse\"\000b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_text_5fto_5fspeech_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_text_5fto_5fspeech_2eproto = {
  false, false, 157, descriptor_table_protodef_text_5fto_5fspeech_2eproto, "text_to_speech.proto", 
  &descriptor_table_text_5fto_5fspeech_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_text_5fto_5fspeech_2eproto::offsets,
  file_level_metadata_text_5fto_5fspeech_2eproto, file_level_enum_descriptors_text_5fto_5fspeech_2eproto, file_level_service_descriptors_text_5fto_5fspeech_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_text_5fto_5fspeech_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_text_5fto_5fspeech_2eproto);
  return descriptor_table_text_5fto_5fspeech_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_text_5fto_5fspeech_2eproto(&descriptor_table_text_5fto_5fspeech_2eproto);
namespace rero {

// ===================================================================

class TTSRequest::_Internal {
 public:
};

TTSRequest::TTSRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:rero.TTSRequest)
}
TTSRequest::TTSRequest(const TTSRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  text_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_text().empty()) {
    text_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_text(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:rero.TTSRequest)
}

void TTSRequest::SharedCtor() {
text_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

TTSRequest::~TTSRequest() {
  // @@protoc_insertion_point(destructor:rero.TTSRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void TTSRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  text_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void TTSRequest::ArenaDtor(void* object) {
  TTSRequest* _this = reinterpret_cast< TTSRequest* >(object);
  (void)_this;
}
void TTSRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TTSRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void TTSRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:rero.TTSRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  text_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TTSRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string text = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_text();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "rero.TTSRequest.text"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* TTSRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rero.TTSRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string text = 1;
  if (this->text().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_text().data(), static_cast<int>(this->_internal_text().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "rero.TTSRequest.text");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_text(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rero.TTSRequest)
  return target;
}

size_t TTSRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rero.TTSRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string text = 1;
  if (this->text().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_text());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TTSRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:rero.TTSRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const TTSRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<TTSRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:rero.TTSRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:rero.TTSRequest)
    MergeFrom(*source);
  }
}

void TTSRequest::MergeFrom(const TTSRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:rero.TTSRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.text().size() > 0) {
    _internal_set_text(from._internal_text());
  }
}

void TTSRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:rero.TTSRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TTSRequest::CopyFrom(const TTSRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rero.TTSRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TTSRequest::IsInitialized() const {
  return true;
}

void TTSRequest::InternalSwap(TTSRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  text_.Swap(&other->text_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata TTSRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class TTSResponse::_Internal {
 public:
};

TTSResponse::TTSResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:rero.TTSResponse)
}
TTSResponse::TTSResponse(const TTSResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  status_ = from.status_;
  // @@protoc_insertion_point(copy_constructor:rero.TTSResponse)
}

void TTSResponse::SharedCtor() {
status_ = false;
}

TTSResponse::~TTSResponse() {
  // @@protoc_insertion_point(destructor:rero.TTSResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void TTSResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void TTSResponse::ArenaDtor(void* object) {
  TTSResponse* _this = reinterpret_cast< TTSResponse* >(object);
  (void)_this;
}
void TTSResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TTSResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void TTSResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:rero.TTSResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  status_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TTSResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bool status = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          status_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* TTSResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rero.TTSResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool status = 1;
  if (this->status() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_status(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rero.TTSResponse)
  return target;
}

size_t TTSResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rero.TTSResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bool status = 1;
  if (this->status() != 0) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TTSResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:rero.TTSResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const TTSResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<TTSResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:rero.TTSResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:rero.TTSResponse)
    MergeFrom(*source);
  }
}

void TTSResponse::MergeFrom(const TTSResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:rero.TTSResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.status() != 0) {
    _internal_set_status(from._internal_status());
  }
}

void TTSResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:rero.TTSResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TTSResponse::CopyFrom(const TTSResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rero.TTSResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TTSResponse::IsInitialized() const {
  return true;
}

void TTSResponse::InternalSwap(TTSResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(status_, other->status_);
}

::PROTOBUF_NAMESPACE_ID::Metadata TTSResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace rero
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::rero::TTSRequest* Arena::CreateMaybeMessage< ::rero::TTSRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rero::TTSRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::rero::TTSResponse* Arena::CreateMaybeMessage< ::rero::TTSResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rero::TTSResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
