﻿cmake_minimum_required (VERSION 3.0.0)

add_executable(Example_DirectX12 main.cpp)

target_include_directories(
    Example_DirectX12
    PRIVATE
    ${EFK_RUNTIME_ROOT}/Effekseer
    ${EFK_RUNTIME_ROOT}/EffekseerRendererDX12
    ${EFK_RUNTIME_ROOT}/EffekseerSoundXAudio2
	../../Dev/Cpp/3rdParty/LLGI/src/
    ../Utils
)

target_link_libraries(
    Example_DirectX12
    PRIVATE
    Effekseer
	LLGI
    EffekseerRendererDX12
    EffekseerSoundXAudio2
    Example_Utils
)