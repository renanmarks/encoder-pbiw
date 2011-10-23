--------------------------------------------------------------------------------
-- r-VEX | Instruction ROM
--------------------------------------------------------------------------------
-- 
-- This file was assembled by PBIWAssembler, the Pattern Based Instruction
-- Word instruction ROM generator for the r-VEX processor./
-- 
--     source file: Fatorial.s
--     r-ASM flags: 
--     date & time: Oct 13, 2011 @ 14:54:16
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
-- Fatorial.s (generated by PBIWAssembler)
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
							"00000000000000000000000000000000"&
							"10000010100100100000000000010000"&
							"10000010100100000000000000001101";

				when x"01" => instr <= "10000010100011000000000000001010"&
							"10000010100011100000000000000100"&
							"10000010100001000000000000000100"&
							"10000010100001100000000000000101";

				when x"02" => instr <= "00000000000000000000000000000010"&
							"00010000000010000001000001100000"&
							"00010110000010100001000001100000"&
							"10111110100000000100000000101001";

				when x"03" => instr <= "00000000000000000000000000000010"&
							"00010000000101000011000011100000"&
							"00010110000101100011000011100000"&
							"00000000000000000000000000000001";

				when x"04" => instr <= "10000010100001000001000000010010"&
							"00010110000001100001000001100000"&
							"00010000000010100001000001100000"&
							"10000010000010000010000010100001";

				when x"05" => instr <= "10000010000101000101000101100010"&
							"00010110000011100100100011100000"&
							"00010000000101100100100011100000"&
							"01001101000000000000000101100001";

				when x"06" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"10000010100100100100100000010000"&
							"10000010000010100010100001100001";

				when x"07" => instr <= "10000010100100000100000000010010"&
							"00010000000010000010100100000000"&
							"00010110000010100010100100000000"&
							"10000010000101100101100011100001";

				when x"08" => instr <= "00000000000000000000000000000010"&
							"00010000000101000101100011000000"&
							"00010110000101100101100011000000"&
							"10000010100011000011000000010001";

				when x"09" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"10000010000001100010000010100001";

				when x"0A" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"10000010000011100101000101100000"&
							"01000011000000000000000001000001";

				when x"0B" => instr <= "00000000000000000000000000000010"&
							"00010000000001000010000101000000"&
							"00010110000010000010000101000000"&
							"00000000000000000000000000000001";

				when x"0C" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000000"&
							"00000000000000000000000000000001";

				when x"0D" => instr <= "00000000000000000000000000000010"&
							"00000000000000000000000000000000"&
							"10000010000001100001000010000000"&
							"01001111000000100000000000000001";

				when others => instr <= "00000000000000000000000000000010"& -- nop
				                        "00000000000000000000000000000000"& -- nop
				                        "00000000000000000000000000000000"& -- nop
				                        "00111110000000000000000000000001"; -- stop
			end case;
		end if;
	end process memory;
end architecture behavioural;


