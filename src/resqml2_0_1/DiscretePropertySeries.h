/*-----------------------------------------------------------------------
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"; you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
-----------------------------------------------------------------------*/
#pragma once

#include "resqml2_0_1/DiscreteProperty.h"

namespace RESQML2_0_1_NS
{
	class DiscretePropertySeries : public DiscreteProperty
	{
	public:

		/**
		* Only to be used in partial transfer context
		*/
		DiscretePropertySeries(gsoap_resqml2_0_1::eml20__DataObjectReference* partialObject) : DiscreteProperty(partialObject) {}

		/**
		* Creates an instance of this class in a gsoap context.
		* @param rep						The representation which supports these property values.
		* @param guid						The guid to set to the fault. If empty then a new guid will be generated.
		* @param title						A title for the instance to create.
		* @param dimension					The dimension of each value (scalar properties == 1).
		* @param attachmentKind				The topological orbit which support each value.
		* @param energisticsPropertyKind	The property type of these property values which must be defined in the standard energistics property type dictionary.
		* @param ts							The associated time series.
		* @param useInterval				Indicates wether the property values will be attached to the time index or to the interval between consecutive time index. 
		*/
		DiscretePropertySeries(RESQML2_NS::AbstractRepresentation * rep, const std::string & guid, const std::string & title,
			const unsigned int & dimension, const gsoap_resqml2_0_1::resqml2__IndexableElements & attachmentKind,
			const gsoap_resqml2_0_1::resqml2__ResqmlPropertyKind & energisticsPropertyKind,
			RESQML2_NS::TimeSeries * ts, const bool & useInterval = false);

		/**
		* Creates an instance of this class in a gsoap context.
		* @param rep						The representation which supports these property values.
		* @param guid						The guid to set to the fault. If empty then a new guid will be generated.
		* @param title						A title for the instance to create.
		* @param dimension					The dimension of each value (scalar properties == 1).
		* @param attachmentKind				The topological orbit which support each value.
		* @param localPropKind				The property type of these property values which must be defined in the EPC document as a local property kind.
		* @param ts							The associated time series.
		* @param useInterval				Indicates wether the property values will be attached to the time index or to the interval between consecutive time index. 
		*/
		DiscretePropertySeries(RESQML2_NS::AbstractRepresentation * rep, const std::string & guid, const std::string & title,
			const unsigned int & dimension, const gsoap_resqml2_0_1::resqml2__IndexableElements & attachmentKind,
			RESQML2_NS::PropertyKind * localPropKind,
			RESQML2_NS::TimeSeries * ts, const bool & useInterval = false);

		/**
		* Creates an instance of this class by wrapping a gsoap instance.
		*/
		DiscretePropertySeries(gsoap_resqml2_0_1::_resqml2__DiscretePropertySeries* fromGsoap): DiscreteProperty(fromGsoap) {}

		/**
		* Destructor does nothing since the memory is managed by the gsoap context.
		*/
		~DiscretePropertySeries() {}

		DLL_IMPORT_OR_EXPORT static const char* XML_TAG;
		DLL_IMPORT_OR_EXPORT virtual std::string getXmlTag() const {return XML_TAG;}

		std::string getResqmlVersion() const {return "2.0.1";}
	};
}
