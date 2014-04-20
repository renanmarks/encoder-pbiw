# Diretório base de includes
# Dessa forma, todos os includes dos sub-diretórios funcionam
project(pbiwencoder)
include_directories("${PROJECT_SOURCE_DIR}")

# Sub-diretórios com códigos a serem compilados
add_subdirectory(GenericAssembly)
add_subdirectory(PBIW)
add_subdirectory(rVex)

# Diretório que contém código base
aux_source_directory(. SRC_LIST)

set(
	MODULES

	PBIW_MODULE
	RVEX_MODULE
	GENERICASSEMBLY_MODULE
)

add_executable(${PROJECT_NAME} ${SRC_LIST})			  # Executável
target_link_libraries(${PROJECT_NAME} ${MODULES})	# Como linkar
