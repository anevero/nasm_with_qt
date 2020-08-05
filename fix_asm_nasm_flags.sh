#!/bin/sh
echo "Removing -fPIC flag from ASM_NASM_FLAGS in \"$1\" project..."
sed -i 's/ASM_NASM_FLAGS =   -fPIC/ASM_NASM_FLAGS =/' ./cmake-build-release/CMakeFiles/$1.dir/flags.make 2>/dev/null
sed -i 's/ASM_NASM_FLAGS =   -fPIC/ASM_NASM_FLAGS =/' ./cmake-build-debug/CMakeFiles/$1.dir/flags.make 2>/dev/null
echo "Finished."
