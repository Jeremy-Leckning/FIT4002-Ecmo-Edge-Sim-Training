// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pulse/cdm/bind/InhalerActions.proto

#include "pulse/cdm/bind/InhalerActions.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_pulse_2fcdm_2fbind_2fActions_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_EquipmentActionData_pulse_2fcdm_2fbind_2fActions_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_pulse_2fcdm_2fbind_2fInhalerActions_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_InhalerActionData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_pulse_2fcdm_2fbind_2fInhaler_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<3> scc_info_InhalerData_pulse_2fcdm_2fbind_2fInhaler_2eproto;
namespace pulse {
namespace cdm {
namespace bind {
class InhalerActionDataDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<InhalerActionData> _instance;
} _InhalerActionData_default_instance_;
class InhalerConfigurationDataDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<InhalerConfigurationData> _instance;
} _InhalerConfigurationData_default_instance_;
}  // namespace bind
}  // namespace cdm
}  // namespace pulse
static void InitDefaultsscc_info_InhalerActionData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pulse::cdm::bind::_InhalerActionData_default_instance_;
    new (ptr) ::pulse::cdm::bind::InhalerActionData();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_InhalerActionData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_InhalerActionData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto}, {
      &scc_info_EquipmentActionData_pulse_2fcdm_2fbind_2fActions_2eproto.base,}};

static void InitDefaultsscc_info_InhalerConfigurationData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pulse::cdm::bind::_InhalerConfigurationData_default_instance_;
    new (ptr) ::pulse::cdm::bind::InhalerConfigurationData();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_InhalerConfigurationData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_InhalerConfigurationData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto}, {
      &scc_info_InhalerActionData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto.base,
      &scc_info_InhalerData_pulse_2fcdm_2fbind_2fInhaler_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_pulse_2fcdm_2fbind_2fInhalerActions_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_pulse_2fcdm_2fbind_2fInhalerActions_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_pulse_2fcdm_2fbind_2fInhalerActions_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_pulse_2fcdm_2fbind_2fInhalerActions_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pulse::cdm::bind::InhalerActionData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pulse::cdm::bind::InhalerActionData, equipmentaction_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pulse::cdm::bind::InhalerConfigurationData, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::pulse::cdm::bind::InhalerConfigurationData, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pulse::cdm::bind::InhalerConfigurationData, inhaleraction_),
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::pulse::cdm::bind::InhalerConfigurationData, Option_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::pulse::cdm::bind::InhalerActionData)},
  { 6, -1, sizeof(::pulse::cdm::bind::InhalerConfigurationData)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pulse::cdm::bind::_InhalerActionData_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pulse::cdm::bind::_InhalerConfigurationData_default_instance_),
};

const char descriptor_table_protodef_pulse_2fcdm_2fbind_2fInhalerActions_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n#pulse/cdm/bind/InhalerActions.proto\022\016p"
  "ulse.cdm.bind\032\034pulse/cdm/bind/Inhaler.pr"
  "oto\032\034pulse/cdm/bind/Actions.proto\"Q\n\021Inh"
  "alerActionData\022<\n\017EquipmentAction\030\001 \001(\0132"
  "#.pulse.cdm.bind.EquipmentActionData\"\261\001\n"
  "\030InhalerConfigurationData\0228\n\rInhalerActi"
  "on\030\001 \001(\0132!.pulse.cdm.bind.InhalerActionD"
  "ata\0224\n\rConfiguration\030\002 \001(\0132\033.pulse.cdm.b"
  "ind.InhalerDataH\000\022\033\n\021ConfigurationFile\030\003"
  " \001(\tH\000B\010\n\006OptionB/\n\032com.kitware.pulse.cd"
  "m.bindH\001\252\002\016pulse.cdm.bindb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_pulse_2fcdm_2fbind_2fInhalerActions_2eproto_deps[2] = {
  &::descriptor_table_pulse_2fcdm_2fbind_2fActions_2eproto,
  &::descriptor_table_pulse_2fcdm_2fbind_2fInhaler_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_pulse_2fcdm_2fbind_2fInhalerActions_2eproto_sccs[2] = {
  &scc_info_InhalerActionData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto.base,
  &scc_info_InhalerConfigurationData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_pulse_2fcdm_2fbind_2fInhalerActions_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_pulse_2fcdm_2fbind_2fInhalerActions_2eproto = {
  false, false, descriptor_table_protodef_pulse_2fcdm_2fbind_2fInhalerActions_2eproto, "pulse/cdm/bind/InhalerActions.proto", 433,
  &descriptor_table_pulse_2fcdm_2fbind_2fInhalerActions_2eproto_once, descriptor_table_pulse_2fcdm_2fbind_2fInhalerActions_2eproto_sccs, descriptor_table_pulse_2fcdm_2fbind_2fInhalerActions_2eproto_deps, 2, 2,
  schemas, file_default_instances, TableStruct_pulse_2fcdm_2fbind_2fInhalerActions_2eproto::offsets,
  file_level_metadata_pulse_2fcdm_2fbind_2fInhalerActions_2eproto, 2, file_level_enum_descriptors_pulse_2fcdm_2fbind_2fInhalerActions_2eproto, file_level_service_descriptors_pulse_2fcdm_2fbind_2fInhalerActions_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_pulse_2fcdm_2fbind_2fInhalerActions_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_pulse_2fcdm_2fbind_2fInhalerActions_2eproto)), true);
namespace pulse {
namespace cdm {
namespace bind {

// ===================================================================

class InhalerActionData::_Internal {
 public:
  static const ::pulse::cdm::bind::EquipmentActionData& equipmentaction(const InhalerActionData* msg);
};

const ::pulse::cdm::bind::EquipmentActionData&
InhalerActionData::_Internal::equipmentaction(const InhalerActionData* msg) {
  return *msg->equipmentaction_;
}
void InhalerActionData::clear_equipmentaction() {
  if (GetArena() == nullptr && equipmentaction_ != nullptr) {
    delete equipmentaction_;
  }
  equipmentaction_ = nullptr;
}
InhalerActionData::InhalerActionData(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:pulse.cdm.bind.InhalerActionData)
}
InhalerActionData::InhalerActionData(const InhalerActionData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_equipmentaction()) {
    equipmentaction_ = new ::pulse::cdm::bind::EquipmentActionData(*from.equipmentaction_);
  } else {
    equipmentaction_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:pulse.cdm.bind.InhalerActionData)
}

void InhalerActionData::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_InhalerActionData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto.base);
  equipmentaction_ = nullptr;
}

InhalerActionData::~InhalerActionData() {
  // @@protoc_insertion_point(destructor:pulse.cdm.bind.InhalerActionData)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void InhalerActionData::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete equipmentaction_;
}

void InhalerActionData::ArenaDtor(void* object) {
  InhalerActionData* _this = reinterpret_cast< InhalerActionData* >(object);
  (void)_this;
}
void InhalerActionData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void InhalerActionData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const InhalerActionData& InhalerActionData::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_InhalerActionData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto.base);
  return *internal_default_instance();
}


void InhalerActionData::Clear() {
// @@protoc_insertion_point(message_clear_start:pulse.cdm.bind.InhalerActionData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && equipmentaction_ != nullptr) {
    delete equipmentaction_;
  }
  equipmentaction_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* InhalerActionData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .pulse.cdm.bind.EquipmentActionData EquipmentAction = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_equipmentaction(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* InhalerActionData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pulse.cdm.bind.InhalerActionData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .pulse.cdm.bind.EquipmentActionData EquipmentAction = 1;
  if (this->has_equipmentaction()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::equipmentaction(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pulse.cdm.bind.InhalerActionData)
  return target;
}

size_t InhalerActionData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pulse.cdm.bind.InhalerActionData)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .pulse.cdm.bind.EquipmentActionData EquipmentAction = 1;
  if (this->has_equipmentaction()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *equipmentaction_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void InhalerActionData::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pulse.cdm.bind.InhalerActionData)
  GOOGLE_DCHECK_NE(&from, this);
  const InhalerActionData* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<InhalerActionData>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pulse.cdm.bind.InhalerActionData)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pulse.cdm.bind.InhalerActionData)
    MergeFrom(*source);
  }
}

void InhalerActionData::MergeFrom(const InhalerActionData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pulse.cdm.bind.InhalerActionData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_equipmentaction()) {
    _internal_mutable_equipmentaction()->::pulse::cdm::bind::EquipmentActionData::MergeFrom(from._internal_equipmentaction());
  }
}

void InhalerActionData::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pulse.cdm.bind.InhalerActionData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InhalerActionData::CopyFrom(const InhalerActionData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pulse.cdm.bind.InhalerActionData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InhalerActionData::IsInitialized() const {
  return true;
}

void InhalerActionData::InternalSwap(InhalerActionData* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(equipmentaction_, other->equipmentaction_);
}

::PROTOBUF_NAMESPACE_ID::Metadata InhalerActionData::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class InhalerConfigurationData::_Internal {
 public:
  static const ::pulse::cdm::bind::InhalerActionData& inhaleraction(const InhalerConfigurationData* msg);
  static const ::pulse::cdm::bind::InhalerData& configuration(const InhalerConfigurationData* msg);
};

const ::pulse::cdm::bind::InhalerActionData&
InhalerConfigurationData::_Internal::inhaleraction(const InhalerConfigurationData* msg) {
  return *msg->inhaleraction_;
}
const ::pulse::cdm::bind::InhalerData&
InhalerConfigurationData::_Internal::configuration(const InhalerConfigurationData* msg) {
  return *msg->Option_.configuration_;
}
void InhalerConfigurationData::set_allocated_configuration(::pulse::cdm::bind::InhalerData* configuration) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  clear_Option();
  if (configuration) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(configuration)->GetArena();
    if (message_arena != submessage_arena) {
      configuration = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, configuration, submessage_arena);
    }
    set_has_configuration();
    Option_.configuration_ = configuration;
  }
  // @@protoc_insertion_point(field_set_allocated:pulse.cdm.bind.InhalerConfigurationData.Configuration)
}
void InhalerConfigurationData::clear_configuration() {
  if (_internal_has_configuration()) {
    if (GetArena() == nullptr) {
      delete Option_.configuration_;
    }
    clear_has_Option();
  }
}
InhalerConfigurationData::InhalerConfigurationData(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:pulse.cdm.bind.InhalerConfigurationData)
}
InhalerConfigurationData::InhalerConfigurationData(const InhalerConfigurationData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_inhaleraction()) {
    inhaleraction_ = new ::pulse::cdm::bind::InhalerActionData(*from.inhaleraction_);
  } else {
    inhaleraction_ = nullptr;
  }
  clear_has_Option();
  switch (from.Option_case()) {
    case kConfiguration: {
      _internal_mutable_configuration()->::pulse::cdm::bind::InhalerData::MergeFrom(from._internal_configuration());
      break;
    }
    case kConfigurationFile: {
      _internal_set_configurationfile(from._internal_configurationfile());
      break;
    }
    case OPTION_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:pulse.cdm.bind.InhalerConfigurationData)
}

void InhalerConfigurationData::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_InhalerConfigurationData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto.base);
  inhaleraction_ = nullptr;
  clear_has_Option();
}

InhalerConfigurationData::~InhalerConfigurationData() {
  // @@protoc_insertion_point(destructor:pulse.cdm.bind.InhalerConfigurationData)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void InhalerConfigurationData::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete inhaleraction_;
  if (has_Option()) {
    clear_Option();
  }
}

void InhalerConfigurationData::ArenaDtor(void* object) {
  InhalerConfigurationData* _this = reinterpret_cast< InhalerConfigurationData* >(object);
  (void)_this;
}
void InhalerConfigurationData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void InhalerConfigurationData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const InhalerConfigurationData& InhalerConfigurationData::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_InhalerConfigurationData_pulse_2fcdm_2fbind_2fInhalerActions_2eproto.base);
  return *internal_default_instance();
}


void InhalerConfigurationData::clear_Option() {
// @@protoc_insertion_point(one_of_clear_start:pulse.cdm.bind.InhalerConfigurationData)
  switch (Option_case()) {
    case kConfiguration: {
      if (GetArena() == nullptr) {
        delete Option_.configuration_;
      }
      break;
    }
    case kConfigurationFile: {
      Option_.configurationfile_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
      break;
    }
    case OPTION_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = OPTION_NOT_SET;
}


void InhalerConfigurationData::Clear() {
// @@protoc_insertion_point(message_clear_start:pulse.cdm.bind.InhalerConfigurationData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && inhaleraction_ != nullptr) {
    delete inhaleraction_;
  }
  inhaleraction_ = nullptr;
  clear_Option();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* InhalerConfigurationData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .pulse.cdm.bind.InhalerActionData InhalerAction = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_inhaleraction(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .pulse.cdm.bind.InhalerData Configuration = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_configuration(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string ConfigurationFile = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_configurationfile();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pulse.cdm.bind.InhalerConfigurationData.ConfigurationFile"));
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

::PROTOBUF_NAMESPACE_ID::uint8* InhalerConfigurationData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pulse.cdm.bind.InhalerConfigurationData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .pulse.cdm.bind.InhalerActionData InhalerAction = 1;
  if (this->has_inhaleraction()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::inhaleraction(this), target, stream);
  }

  // .pulse.cdm.bind.InhalerData Configuration = 2;
  if (_internal_has_configuration()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::configuration(this), target, stream);
  }

  // string ConfigurationFile = 3;
  if (_internal_has_configurationfile()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_configurationfile().data(), static_cast<int>(this->_internal_configurationfile().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "pulse.cdm.bind.InhalerConfigurationData.ConfigurationFile");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_configurationfile(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pulse.cdm.bind.InhalerConfigurationData)
  return target;
}

size_t InhalerConfigurationData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pulse.cdm.bind.InhalerConfigurationData)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .pulse.cdm.bind.InhalerActionData InhalerAction = 1;
  if (this->has_inhaleraction()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *inhaleraction_);
  }

  switch (Option_case()) {
    // .pulse.cdm.bind.InhalerData Configuration = 2;
    case kConfiguration: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *Option_.configuration_);
      break;
    }
    // string ConfigurationFile = 3;
    case kConfigurationFile: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_configurationfile());
      break;
    }
    case OPTION_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void InhalerConfigurationData::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pulse.cdm.bind.InhalerConfigurationData)
  GOOGLE_DCHECK_NE(&from, this);
  const InhalerConfigurationData* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<InhalerConfigurationData>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pulse.cdm.bind.InhalerConfigurationData)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pulse.cdm.bind.InhalerConfigurationData)
    MergeFrom(*source);
  }
}

void InhalerConfigurationData::MergeFrom(const InhalerConfigurationData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pulse.cdm.bind.InhalerConfigurationData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_inhaleraction()) {
    _internal_mutable_inhaleraction()->::pulse::cdm::bind::InhalerActionData::MergeFrom(from._internal_inhaleraction());
  }
  switch (from.Option_case()) {
    case kConfiguration: {
      _internal_mutable_configuration()->::pulse::cdm::bind::InhalerData::MergeFrom(from._internal_configuration());
      break;
    }
    case kConfigurationFile: {
      _internal_set_configurationfile(from._internal_configurationfile());
      break;
    }
    case OPTION_NOT_SET: {
      break;
    }
  }
}

void InhalerConfigurationData::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pulse.cdm.bind.InhalerConfigurationData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InhalerConfigurationData::CopyFrom(const InhalerConfigurationData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pulse.cdm.bind.InhalerConfigurationData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InhalerConfigurationData::IsInitialized() const {
  return true;
}

void InhalerConfigurationData::InternalSwap(InhalerConfigurationData* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(inhaleraction_, other->inhaleraction_);
  swap(Option_, other->Option_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata InhalerConfigurationData::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace bind
}  // namespace cdm
}  // namespace pulse
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pulse::cdm::bind::InhalerActionData* Arena::CreateMaybeMessage< ::pulse::cdm::bind::InhalerActionData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::pulse::cdm::bind::InhalerActionData >(arena);
}
template<> PROTOBUF_NOINLINE ::pulse::cdm::bind::InhalerConfigurationData* Arena::CreateMaybeMessage< ::pulse::cdm::bind::InhalerConfigurationData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::pulse::cdm::bind::InhalerConfigurationData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>