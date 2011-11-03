--------------------------------------------------------------------------------
-- r-VEX | Instruction ROM
--------------------------------------------------------------------------------
-- 
-- This file was assembled by PBIWAssembler, the Pattern Based Instruction
-- Word instruction ROM generator for the r-VEX processor./
-- 
--     source file: Switch.s
--     r-ASM flags: 
--     date & time: Oct 13, 2011 @ 14:54:41
-- 
-- r-VEX is
-- Copyright (c) 2008, Thijs van As <t.vanas@gmail.com>
-- 
-- PBIWAssembler is free hardware: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.
-- 
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
-- 
-- You should have received a copy of the GNU General Public License
-- along with this program.  If not, see <http://www.gnu.org/licenses/>.
-- 
--------------------------------------------------------------------------------
-- Switch.s (generated by PBIWAssembler)
--------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity i_mem is
	port ( reset   : in std_logic;                        -- system reset
	       address : in std_logic_vector(7 downto 0);     -- address of instruction to be read

	       instr   : out std_logic_vector(127 downto 0)); -- instruction (4 syllables)
end entity i_mem;


architecture behavioural of i_mem is
begin
	memory : process(address, reset)
	begin
		if (reset = '1') then
			instr <= x"00000000000000000000000000000000";
		else
			case address is

				when x"00" => instr <= "00000000000000000000000000000010"&
							"10000010100011100000000000000100"&
							"00000010110000000001000000000000"&
							"10000010100000111111111100000001";

				when x"01" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000010110000000010000000100001";

				when x"02" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000010110000000001100010000001";

				when x"03" => instr <= "00100010000010000001100000000010"&
							"10110010100011000001000000001000"&
							"10110010100010100001000000000100"&
							"11000000100000000001000000101001";

				when x"04" => instr <= "00100010000101000001100000010010"&
							"10110010100100100001000000000100"&
							"10110010000100000001000000000000"&
							"11001000000000000010100011000101";

				when x"05" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"11001000000000000100000100100000"&
							"01001101000000000000010010100001";

				when x"06" => instr <= "00000000000000000000000000000010"&
							"00010000000010100001000010000000"&
							"00010110000011000001000010000000"&
							"01001011000000000000001011000101";

				when x"07" => instr <= "00000000000000000000000000000010"&
							"00010000000100000011100101000000"&
							"00010110000100100011100101000000"&
							"00000000000000000000000000000001";

				when x"08" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"10000010000010100010100011000001";

				when x"09" => instr <= "00101100000001100010100000000010"&
							"00000000000000000000000000000000"&
							"10000010000100000100000100100000"&
							"01001011000000000000000110000001";

				when x"0A" => instr <= "00101100000001100100000000010010"&
							"10000010100001000001000000001000"&
							"10000010100011100011100000001000"&
							"00000000000000000000000000000001";

				when x"0B" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"10000010100001100001100000100000"&
							"01000011000000000000000001100001";

				when x"0C" => instr <= "00100010000010000001100000010010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"10110010100000000001000000010001";

				when x"0D" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"0E" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"01001101000000000000001000100001";

				when x"0F" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"10000010100001000001000000001000"&
							"10000010000010000011100010000001";

				when x"10" => instr <= "00101100000001100010000000010010"&
							"00000000000000000000000000000000"&
							"10000010100011100011100000001000"&
							"01000011000000000000000101100001";

				when x"11" => instr <= "00100010000010000001100000010010"&
							"10000010100001000001000000001000"&
							"10000010100011100011100000001000"&
							"00000000000000000000000000000001";

				when x"12" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"13" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"14" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"10000010100010000010000000000101";

				when x"15" => instr <= "00101100000001100010000000010010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"01000011000000000000000101100001";

				when x"16" => instr <= "00100010000010000001100000000010"&
							"00010000000100100011100101000000"&
							"00010110000101100011100101000000"&
							"10110010100000000001000000010101";

				when x"17" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"18" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"10000010000100000100100101100000"&
							"01001101000000000000001110000101";

				when x"19" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"10000010000010000001000010000001";

				when x"1A" => instr <= "00101100000001100010000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"01001011000000000000000110000001";

				when x"1B" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"01000011000000000000000101000001";

				when x"1C" => instr <= "00100010000010000001100000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"1D" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"1E" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"1F" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"10000010100010000010000000000101";

				when x"20" => instr <= "00101100000001100010000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"01001101000000000000010001000001";

				when x"21" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"01000011000000000000000110000001";

				when x"22" => instr <= "00000000000000000000000000000010"&
							"00010000000010000011100101000000"&
							"00010110000100100011100101000000"&
							"00000000000000000000000000000001";

				when x"23" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"24" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"10000010000100000010000100100000"&
							"01000011000000000000000101000001";

				when x"25" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000010110000000001100000000000"&
							"01001111000000100000000000000001";

				when others => instr <= "00000000000000000000000000000010"& -- nop
				                        "00000000000000000000000000000000"& -- nop
				                        "00000000000000000000000000000000"& -- nop
				                        "00111110000000000000000000000001"; -- stop
			end case;
		end if;
	end process memory;
end architecture behavioural;

