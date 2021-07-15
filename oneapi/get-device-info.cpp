//==============================================================
// Copyright © 2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
// =============================================================
#include <CL/sycl.hpp>

using namespace cl::sycl;

int main() {
  //# Create a device queue with device selector
  
  //gpu_selector selector;
  cpu_selector selector;
  //default_selector selector;
  //host_selector selector;
  
  queue q(selector);

  //# Print the device info
  auto device = q.get_device();
  std::cout << "device_type: " << static_cast<pi_uint64>(device.get_info<info::device::device_type>()) << std::endl;
  std::cout << "vendor_id: " << device.get_info<info::device::vendor_id>() << std::endl;
  std::cout << "max_compute_units: " << device.get_info<info::device::max_compute_units>() << std::endl;
  std::cout << "max_work_item_dimensions: " << device.get_info<info::device::max_work_item_dimensions>() << std::endl;
  //
  detail::array<3> max_work_item_sizes = device.get_info<info::device::max_work_item_sizes>();
  std::cout << "max_work_item_sizes: "; 
  for(int i = 0; i < 3; i++){std::cout << std::endl << "  " << max_work_item_sizes.get(i);}
  std::cout << std::endl;
  //
  std::cout << "max_work_group_size: " << device.get_info<info::device::max_work_group_size>() << std::endl;
  std::cout << "preferred_vector_width_char: " << device.get_info<info::device::preferred_vector_width_char>() << std::endl;
  std::cout << "preferred_vector_width_short: " << device.get_info<info::device::preferred_vector_width_short>() << std::endl;
  std::cout << "preferred_vector_width_int: " << device.get_info<info::device::preferred_vector_width_int>() << std::endl;
  std::cout << "preferred_vector_width_long: " << device.get_info<info::device::preferred_vector_width_long>() << std::endl;
  std::cout << "preferred_vector_width_float: " << device.get_info<info::device::preferred_vector_width_float>() << std::endl;
  std::cout << "preferred_vector_width_double: " << device.get_info<info::device::preferred_vector_width_double>() << std::endl;
  std::cout << "preferred_vector_width_half: " << device.get_info<info::device::preferred_vector_width_half>() << std::endl;
  std::cout << "native_vector_width_char: " << device.get_info<info::device::native_vector_width_char>() << std::endl;
  std::cout << "native_vector_width_short: " << device.get_info<info::device::native_vector_width_short>() << std::endl;
  std::cout << "native_vector_width_int: " << device.get_info<info::device::native_vector_width_int>() << std::endl;
  std::cout << "native_vector_width_long: " << device.get_info<info::device::native_vector_width_long>() << std::endl;
  std::cout << "native_vector_width_float: " << device.get_info<info::device::native_vector_width_float>() << std::endl;
  std::cout << "native_vector_width_double: " << device.get_info<info::device::native_vector_width_double>() << std::endl;
  std::cout << "native_vector_width_half: " << device.get_info<info::device::native_vector_width_half>() << std::endl;
  std::cout << "max_clock_frequency: " << device.get_info<info::device::max_clock_frequency>() << std::endl;
  std::cout << "address_bits: " << device.get_info<info::device::address_bits>() << std::endl;
  std::cout << "max_mem_alloc_size: " << device.get_info<info::device::max_mem_alloc_size>() << std::endl;
  std::cout << "image_support: " << device.get_info<info::device::image_support>() << std::endl;
  std::cout << "max_read_image_args: " << device.get_info<info::device::max_read_image_args>() << std::endl;
  std::cout << "max_write_image_args: " << device.get_info<info::device::max_write_image_args>() << std::endl;
  std::cout << "image2d_max_height: " << device.get_info<info::device::image2d_max_height>() << std::endl;
  std::cout << "image2d_max_width: " << device.get_info<info::device::image2d_max_width>() << std::endl;
  std::cout << "image3d_max_height: " << device.get_info<info::device::image3d_max_height>() << std::endl;
  std::cout << "image3d_max_width: " << device.get_info<info::device::image3d_max_width>() << std::endl;
  std::cout << "image3d_max_depth: " << device.get_info<info::device::image3d_max_depth>() << std::endl;
  std::cout << "image_max_buffer_size: " << device.get_info<info::device::image_max_buffer_size>() << std::endl;
  std::cout << "image_max_array_size: " << device.get_info<info::device::image_max_array_size>() << std::endl;
  std::cout << "max_samplers: " << device.get_info<info::device::max_samplers>() << std::endl;
  std::cout << "max_parameter_size: " << device.get_info<info::device::max_parameter_size>() << std::endl;
  std::cout << "mem_base_addr_align: " << device.get_info<info::device::mem_base_addr_align>() << std::endl;
  //
  std::vector<sycl::info::fp_config> half_fp_config = device.get_info<info::device::half_fp_config>();
  std::cout << "half_fp_config: "; 
  for(auto& h: half_fp_config){std::cout << std::endl << "  " << static_cast<cl_device_fp_config>(h);}
  std::cout << std::endl;
  //
  std::vector<sycl::info::fp_config> single_fp_config = device.get_info<info::device::single_fp_config>();
  std::cout << "single_fp_config: "; 
  for(auto& s: single_fp_config){std::cout << std::endl << "  " << static_cast<cl_device_fp_config>(s);}
  std::cout << std::endl;
  //
  std::vector<sycl::info::fp_config> double_fp_config = device.get_info<info::device::double_fp_config>();
  std::cout << "double_fp_config: "; 
  for(auto& d: double_fp_config){std::cout << std::endl << "  " << static_cast<cl_device_fp_config>(d);}
  std::cout << std::endl;
  //
  std::cout << "global_mem_cache_type: " << static_cast<int>(device.get_info<info::device::global_mem_cache_type>()) << std::endl;
  std::cout << "global_mem_cache_line_size: " << device.get_info<info::device::global_mem_cache_line_size>() << std::endl;
  std::cout << "global_mem_cache_size: " << device.get_info<info::device::global_mem_cache_size>() << std::endl;
  std::cout << "global_mem_size: " << device.get_info<info::device::global_mem_size>() << std::endl;
  std::cout << "max_constant_buffer_size: " << device.get_info<info::device::max_constant_buffer_size>() << std::endl;
  std::cout << "max_constant_args: " << device.get_info<info::device::max_constant_args>() << std::endl;
  std::cout << "local_mem_type: " << static_cast<int>(device.get_info<info::device::local_mem_type>()) << std::endl;
  std::cout << "local_mem_size: " << device.get_info<info::device::local_mem_size>() << std::endl;
  std::cout << "error_correction_support: " << device.get_info<info::device::error_correction_support>() << std::endl;
  std::cout << "host_unified_memory: " << device.get_info<info::device::host_unified_memory>() << std::endl;
  std::cout << "profiling_timer_resolution: " << device.get_info<info::device::profiling_timer_resolution>() << std::endl;
  std::cout << "is_endian_little: " << device.get_info<info::device::is_endian_little>() << std::endl;
  std::cout << "is_available: " << device.get_info<info::device::is_available>() << std::endl;
  std::cout << "is_compiler_available: " << device.get_info<info::device::is_compiler_available>() << std::endl;
  std::cout << "is_linker_available: " << device.get_info<info::device::is_linker_available>() << std::endl;
  //
  std::vector<info::execution_capability> execution_capabilities = device.get_info<info::device::execution_capabilities>();
  std::cout << "execution_capabilities: "; 
  for(auto& e: execution_capabilities){std::cout << std::endl << "  " << static_cast<unsigned int>(e);}
  std::cout << std::endl;
  //
  std::cout << "queue_profiling: " << device.get_info<info::device::queue_profiling>() << std::endl;
  //
  std::vector<std::string> built_in_kernels = device.get_info<info::device::built_in_kernels>();
  std::cout << "built_in_kernels: "; 
  for(auto& b: built_in_kernels){std::cout << std::endl << "  " << b;}
  std::cout << std::endl;
  //
  cl::sycl::platform platform = device.get_info<info::device::platform>();
  const std::string &platform_name = platform.get_info<info::platform::name>();
  std::cout << "platform_name: " << platform_name << std::endl;
  //
  std::cout << "name: " << device.get_info<info::device::name>() << std::endl;
  std::cout << "vendor: " << device.get_info<info::device::vendor>() << std::endl;
  std::cout << "driver_version: " << device.get_info<info::device::driver_version>() << std::endl;
  std::cout << "profile: " << device.get_info<info::device::profile>() << std::endl;
  std::cout << "version: " << device.get_info<info::device::version>() << std::endl;
  std::cout << "opencl_c_version: " << device.get_info<info::device::opencl_c_version>() << std::endl;
  //
  std::vector<std::string> extensions = device.get_info<info::device::extensions>();
  std::cout << "extensions: "; 
  for(auto& e: extensions){std::cout << std::endl << "  " << e;}
  std::cout << std::endl;
  //
  std::cout << "printf_buffer_size: " << device.get_info<info::device::printf_buffer_size>() << std::endl;
  std::cout << "preferred_interop_user_sync: " << device.get_info<info::device::preferred_interop_user_sync>() << std::endl;
  //
  //cl::sycl::device parent_device = device.get_info<info::device::parent_device>();
  //std::cout << "parent_device_name: " << parent_device.get_info<info::device::name>() << std::endl;
  //
  std::cout << "partition_max_sub_devices: " << device.get_info<info::device::partition_max_sub_devices>() << std::endl;
  //std::cout << "partition_properties: " << device.get_info<info::device::partition_properties>() << std::endl;
  //std::cout << "partition_affinity_domains: " << device.get_info<info::device::partition_affinity_domains>() << std::endl;
  //std::cout << "partition_type_property: " << device.get_info<info::device::partition_type_property>() << std::endl;
  //std::cout << "partition_type_affinity_domain: " << device.get_info<info::device::partition_type_affinity_domain>() << std::endl;
  std::cout << "reference_count: " << device.get_info<info::device::reference_count>() << std::endl;
  return 0;
}
