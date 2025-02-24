#ifndef _PSYKO_ERRORCODES_
#define _PSYKO_ERRORCODES_

#define WINDOW_CREATION_FAILED 0x100
#define INVALID_PARAMETER 0x101
#define MEMORY_ALLOCATION_FAILED 0x102

#define D3D_VERSION_NOT_SUPPORTED 0x200
#define D3D_DEVICE_CONTEXT_CREATION_FAILED 0x201
#define D3D_QUERY_INTERFACE_FAILED 0x202
#define D3D_SWAP_CHAIN_CREATION_FAILED 0x203
#define D3D_DEPTH_STENCIL_BUFFER_CREATION_FAILED 0x204
#define D3D_BACKBUFFER_CREATION_FAILED 0x205
#define D3D_BUFFER_CREATION_FAILED 0x206
#define D3D_EFFECT_CREATION_FAILED 0x207
#define D3D_INPUT_LAYOUT_CREATION_FAILED 0x208
#define D3D_TEXTURE_CREATION_FAILED 0x209
#define D3D_FAILED_TO_MAP_RESOURCE 0x20a;

#define NUI_SENSOR_QUERY_FAILED 0x500
#define NUI_SENSOR_NOT_FOUND 0x501
#define NUI_SENSOR_NOT_AVAILABLE 0x502
#define NUI_FAILED_TO_INITIALIZE_STREAM 0x503
#define NUI_FAILED_TO_GET_FRAME 0x504
#define NUI_FAILED_TO_LOCK_TEXTURE 0x505

#define IO_COULD_NOT_OPEN_FILE 0x600
#define IO_COULD_NOT_PARSE_FILE 0x601

#endif