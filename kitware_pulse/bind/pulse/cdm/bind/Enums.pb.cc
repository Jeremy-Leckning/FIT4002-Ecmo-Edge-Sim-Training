// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pulse/cdm/bind/Enums.proto

#include "pulse/cdm/bind/Enums.pb.h"

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
namespace pulse {
namespace cdm {
namespace bind {
}  // namespace bind
}  // namespace cdm
}  // namespace pulse
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_pulse_2fcdm_2fbind_2fEnums_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_pulse_2fcdm_2fbind_2fEnums_2eproto[4];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_pulse_2fcdm_2fbind_2fEnums_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_pulse_2fcdm_2fbind_2fEnums_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_pulse_2fcdm_2fbind_2fEnums_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032pulse/cdm/bind/Enums.proto\022\016pulse.cdm."
  "bind**\n\005eSide\022\014\n\010NullSide\020\000\022\010\n\004Left\020\001\022\t\n"
  "\005Right\020\002*+\n\005eGate\022\014\n\010NullGate\020\000\022\010\n\004Open\020"
  "\001\022\n\n\006Closed\020\002**\n\007eSwitch\022\016\n\nNullSwitch\020\000"
  "\022\007\n\003Off\020\001\022\006\n\002On\020\002*B\n\007eCharge\022\016\n\nNullChar"
  "ge\020\000\022\014\n\010Negative\020\001\022\013\n\007Neutral\020\002\022\014\n\010Posit"
  "ive\020\003B/\n\032com.kitware.pulse.cdm.bindH\001\252\002\016"
  "pulse.cdm.bindb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto_sccs[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto = {
  false, false, descriptor_table_protodef_pulse_2fcdm_2fbind_2fEnums_2eproto, "pulse/cdm/bind/Enums.proto", 302,
  &descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto_once, descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto_sccs, descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto_deps, 0, 0,
  schemas, file_default_instances, TableStruct_pulse_2fcdm_2fbind_2fEnums_2eproto::offsets,
  file_level_metadata_pulse_2fcdm_2fbind_2fEnums_2eproto, 0, file_level_enum_descriptors_pulse_2fcdm_2fbind_2fEnums_2eproto, file_level_service_descriptors_pulse_2fcdm_2fbind_2fEnums_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_pulse_2fcdm_2fbind_2fEnums_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto)), true);
namespace pulse {
namespace cdm {
namespace bind {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* eSide_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto);
  return file_level_enum_descriptors_pulse_2fcdm_2fbind_2fEnums_2eproto[0];
}
bool eSide_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* eGate_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto);
  return file_level_enum_descriptors_pulse_2fcdm_2fbind_2fEnums_2eproto[1];
}
bool eGate_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* eSwitch_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto);
  return file_level_enum_descriptors_pulse_2fcdm_2fbind_2fEnums_2eproto[2];
}
bool eSwitch_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* eCharge_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto);
  return file_level_enum_descriptors_pulse_2fcdm_2fbind_2fEnums_2eproto[3];
}
bool eCharge_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace bind
}  // namespace cdm
}  // namespace pulse
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>