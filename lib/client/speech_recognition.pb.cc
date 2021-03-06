// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: speech_recognition.proto

#include "speech_recognition.pb.h"

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
constexpr SpeechRecognitionResult::SpeechRecognitionResult(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : result_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct SpeechRecognitionResultDefaultTypeInternal {
  constexpr SpeechRecognitionResultDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~SpeechRecognitionResultDefaultTypeInternal() {}
  union {
    SpeechRecognitionResult _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT SpeechRecognitionResultDefaultTypeInternal _SpeechRecognitionResult_default_instance_;
}  // namespace rero
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_speech_5frecognition_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_speech_5frecognition_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_speech_5frecognition_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_speech_5frecognition_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rero::SpeechRecognitionResult, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rero::SpeechRecognitionResult, result_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::rero::SpeechRecognitionResult)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::rero::_SpeechRecognitionResult_default_instance_),
};

const char descriptor_table_protodef_speech_5frecognition_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\030speech_recognition.proto\022\004rero\032\013audio."
  "proto\")\n\027SpeechRecognitionResult\022\016\n\006resu"
  "lt\030\001 \001(\t2V\n\021SpeechRecognition\022A\n\017Recogni"
  "zeSpeech\022\013.rero.Audio\032\035.rero.SpeechRecog"
  "nitionResult\"\000(\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_speech_5frecognition_2eproto_deps[1] = {
  &::descriptor_table_audio_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_speech_5frecognition_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_speech_5frecognition_2eproto = {
  false, false, 184, descriptor_table_protodef_speech_5frecognition_2eproto, "speech_recognition.proto", 
  &descriptor_table_speech_5frecognition_2eproto_once, descriptor_table_speech_5frecognition_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_speech_5frecognition_2eproto::offsets,
  file_level_metadata_speech_5frecognition_2eproto, file_level_enum_descriptors_speech_5frecognition_2eproto, file_level_service_descriptors_speech_5frecognition_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_speech_5frecognition_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_speech_5frecognition_2eproto);
  return descriptor_table_speech_5frecognition_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_speech_5frecognition_2eproto(&descriptor_table_speech_5frecognition_2eproto);
namespace rero {

// ===================================================================

class SpeechRecognitionResult::_Internal {
 public:
};

SpeechRecognitionResult::SpeechRecognitionResult(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:rero.SpeechRecognitionResult)
}
SpeechRecognitionResult::SpeechRecognitionResult(const SpeechRecognitionResult& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  result_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_result().empty()) {
    result_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_result(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:rero.SpeechRecognitionResult)
}

void SpeechRecognitionResult::SharedCtor() {
result_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

SpeechRecognitionResult::~SpeechRecognitionResult() {
  // @@protoc_insertion_point(destructor:rero.SpeechRecognitionResult)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SpeechRecognitionResult::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  result_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void SpeechRecognitionResult::ArenaDtor(void* object) {
  SpeechRecognitionResult* _this = reinterpret_cast< SpeechRecognitionResult* >(object);
  (void)_this;
}
void SpeechRecognitionResult::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SpeechRecognitionResult::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void SpeechRecognitionResult::Clear() {
// @@protoc_insertion_point(message_clear_start:rero.SpeechRecognitionResult)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  result_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SpeechRecognitionResult::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_result();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "rero.SpeechRecognitionResult.result"));
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

::PROTOBUF_NAMESPACE_ID::uint8* SpeechRecognitionResult::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rero.SpeechRecognitionResult)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string result = 1;
  if (this->result().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_result().data(), static_cast<int>(this->_internal_result().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "rero.SpeechRecognitionResult.result");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_result(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rero.SpeechRecognitionResult)
  return target;
}

size_t SpeechRecognitionResult::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rero.SpeechRecognitionResult)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string result = 1;
  if (this->result().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_result());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SpeechRecognitionResult::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:rero.SpeechRecognitionResult)
  GOOGLE_DCHECK_NE(&from, this);
  const SpeechRecognitionResult* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SpeechRecognitionResult>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:rero.SpeechRecognitionResult)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:rero.SpeechRecognitionResult)
    MergeFrom(*source);
  }
}

void SpeechRecognitionResult::MergeFrom(const SpeechRecognitionResult& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:rero.SpeechRecognitionResult)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.result().size() > 0) {
    _internal_set_result(from._internal_result());
  }
}

void SpeechRecognitionResult::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:rero.SpeechRecognitionResult)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SpeechRecognitionResult::CopyFrom(const SpeechRecognitionResult& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rero.SpeechRecognitionResult)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SpeechRecognitionResult::IsInitialized() const {
  return true;
}

void SpeechRecognitionResult::InternalSwap(SpeechRecognitionResult* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  result_.Swap(&other->result_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata SpeechRecognitionResult::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace rero
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::rero::SpeechRecognitionResult* Arena::CreateMaybeMessage< ::rero::SpeechRecognitionResult >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rero::SpeechRecognitionResult >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
