cmake_minimum_required(VERSION 3.24)
project(dvb_s2)

set(CMAKE_CXX_STANDARD 17)

add_executable(dvb_s2 main.cpp getKbch.h getKbch.cpp generate_crc.h generate_crc.cpp dvb_s2.h get_bbheader.h get_bbheader.cpp crc_data.h crc_data.cpp scraming.h scraming.cpp dvb_bch.cpp dvb_bch.h dvb_ldpc.cpp dvb_ldpc.h data_interweave.cpp data_interweave.h data_reflect.cpp data_reflect.h dvb_pl.cpp dvb_pl.h)
