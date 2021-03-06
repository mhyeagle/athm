// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: creativeinfo.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "creativeinfo.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace ad {

namespace {

const ::google::protobuf::Descriptor* Creative_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Creative_reflection_ = NULL;
const ::google::protobuf::Descriptor* CreativeInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CreativeInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_creativeinfo_2eproto() {
  protobuf_AddDesc_creativeinfo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "creativeinfo.proto");
  GOOGLE_CHECK(file != NULL);
  Creative_descriptor_ = file->message_type(0);
  static const int Creative_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Creative, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Creative, info_),
  };
  Creative_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Creative_descriptor_,
      Creative::default_instance_,
      Creative_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Creative, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Creative, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Creative));
  CreativeInfo_descriptor_ = file->message_type(1);
  static const int CreativeInfo_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreativeInfo, creative_),
  };
  CreativeInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CreativeInfo_descriptor_,
      CreativeInfo::default_instance_,
      CreativeInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreativeInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreativeInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CreativeInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_creativeinfo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Creative_descriptor_, &Creative::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CreativeInfo_descriptor_, &CreativeInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_creativeinfo_2eproto() {
  delete Creative::default_instance_;
  delete Creative_reflection_;
  delete CreativeInfo::default_instance_;
  delete CreativeInfo_reflection_;
}

void protobuf_AddDesc_creativeinfo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022creativeinfo.proto\022\002ad\"$\n\010Creative\022\n\n\002"
    "id\030\001 \002(\014\022\014\n\004info\030\002 \002(\014\".\n\014CreativeInfo\022\036"
    "\n\010creative\030\001 \003(\0132\014.ad.Creative", 110);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "creativeinfo.proto", &protobuf_RegisterTypes);
  Creative::default_instance_ = new Creative();
  CreativeInfo::default_instance_ = new CreativeInfo();
  Creative::default_instance_->InitAsDefaultInstance();
  CreativeInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_creativeinfo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_creativeinfo_2eproto {
  StaticDescriptorInitializer_creativeinfo_2eproto() {
    protobuf_AddDesc_creativeinfo_2eproto();
  }
} static_descriptor_initializer_creativeinfo_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Creative::kIdFieldNumber;
const int Creative::kInfoFieldNumber;
#endif  // !_MSC_VER

Creative::Creative()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Creative::InitAsDefaultInstance() {
}

Creative::Creative(const Creative& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Creative::SharedCtor() {
  _cached_size_ = 0;
  id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  info_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Creative::~Creative() {
  SharedDtor();
}

void Creative::SharedDtor() {
  if (id_ != &::google::protobuf::internal::kEmptyString) {
    delete id_;
  }
  if (info_ != &::google::protobuf::internal::kEmptyString) {
    delete info_;
  }
  if (this != default_instance_) {
  }
}

void Creative::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Creative::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Creative_descriptor_;
}

const Creative& Creative::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_creativeinfo_2eproto();
  return *default_instance_;
}

Creative* Creative::default_instance_ = NULL;

Creative* Creative::New() const {
  return new Creative;
}

void Creative::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_id()) {
      if (id_ != &::google::protobuf::internal::kEmptyString) {
        id_->clear();
      }
    }
    if (has_info()) {
      if (info_ != &::google::protobuf::internal::kEmptyString) {
        info_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Creative::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_id()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_info;
        break;
      }

      // required bytes info = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_info()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Creative::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required bytes id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->id(), output);
  }

  // required bytes info = 2;
  if (has_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Creative::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required bytes id = 1;
  if (has_id()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->id(), target);
  }

  // required bytes info = 2;
  if (has_info()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Creative::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->id());
    }

    // required bytes info = 2;
    if (has_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->info());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Creative::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Creative* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Creative*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Creative::MergeFrom(const Creative& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_info()) {
      set_info(from.info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Creative::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Creative::CopyFrom(const Creative& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Creative::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Creative::Swap(Creative* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(info_, other->info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Creative::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Creative_descriptor_;
  metadata.reflection = Creative_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CreativeInfo::kCreativeFieldNumber;
#endif  // !_MSC_VER

CreativeInfo::CreativeInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void CreativeInfo::InitAsDefaultInstance() {
}

CreativeInfo::CreativeInfo(const CreativeInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void CreativeInfo::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CreativeInfo::~CreativeInfo() {
  SharedDtor();
}

void CreativeInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CreativeInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CreativeInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CreativeInfo_descriptor_;
}

const CreativeInfo& CreativeInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_creativeinfo_2eproto();
  return *default_instance_;
}

CreativeInfo* CreativeInfo::default_instance_ = NULL;

CreativeInfo* CreativeInfo::New() const {
  return new CreativeInfo;
}

void CreativeInfo::Clear() {
  creative_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CreativeInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .ad.Creative creative = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_creative:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_creative()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_creative;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void CreativeInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .ad.Creative creative = 1;
  for (int i = 0; i < this->creative_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->creative(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* CreativeInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .ad.Creative creative = 1;
  for (int i = 0; i < this->creative_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->creative(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int CreativeInfo::ByteSize() const {
  int total_size = 0;

  // repeated .ad.Creative creative = 1;
  total_size += 1 * this->creative_size();
  for (int i = 0; i < this->creative_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->creative(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CreativeInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CreativeInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CreativeInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CreativeInfo::MergeFrom(const CreativeInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  creative_.MergeFrom(from.creative_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CreativeInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CreativeInfo::CopyFrom(const CreativeInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CreativeInfo::IsInitialized() const {

  for (int i = 0; i < creative_size(); i++) {
    if (!this->creative(i).IsInitialized()) return false;
  }
  return true;
}

void CreativeInfo::Swap(CreativeInfo* other) {
  if (other != this) {
    creative_.Swap(&other->creative_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CreativeInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CreativeInfo_descriptor_;
  metadata.reflection = CreativeInfo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace ad

// @@protoc_insertion_point(global_scope)
