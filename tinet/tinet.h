#pragma once

/*
* TINet
* https://tulipindicators.org/
* Copyright (c) 2010-2018 Tulip Charts LLC
* Lewis Van Winkle (LV@tulipcharts.org)
*
* This file is part of TINet (Tulip Indicators).
*
* TINet is free software: you can redistribute it and/or modify it
* under the terms of the GNU Lesser General Public License as published by the
* Free Software Foundation, either version 3 of the License, or (at your
* option) any later version.
*
* TINet is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
* for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with TINet.  If not, see <http://www.gnu.org/licenses/>.
*
*/


using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;


namespace tinet {

	public ref class util
	{
	public:
		
		static String^ get_ti_version() {
			return ti_version();
		}
		
	}; //class util



	public ref class indicator
	{
	private:
		int index;
		String ^m_name;
		String ^m_full_name;
		cli::array<String^>^ m_inputs;
		cli::array<String^>^ m_options;
		cli::array<String^>^ m_outputs;

	public:
		indicator(int index, String ^name, String ^full_name, String ^inputs, String ^options, String ^outputs) {
			
			this->index = index;
			this->m_name = name;
			this->m_full_name = full_name;
			this->m_inputs = inputs->Split('|');
			this->m_options = options->Split('|');
			this->m_outputs = outputs->Split('|');

		}

		String ^name() {
			return this->m_name;
		}

		String ^full_name() {
			return this->m_full_name;
		}

		int run(cli::array<cli::array<double>^>^ inputs, cli::array<double>^ options, cli::array<cli::array<double>^>^ outputs) {
			return indicator_run(this->index, inputs, options, outputs);
		}

		int start(cli::array<double>^ options) {
			return indicator_start(this->index, options);
		}


		cli::array<String^>^ inputs() {
			return this->m_inputs;
		}

		cli::array<String^>^ options() {
			return this->m_options;
		}

		cli::array<String^>^ outputs() {
			return this->m_outputs;
		}

	}; //class indicator


	

	public ref class indicators
	{
	public:
#include "inds.cpp"
	}; //namespace indicators

}//namespace tinet


