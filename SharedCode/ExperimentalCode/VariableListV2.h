/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#pragma once
#if !defined(VariableListV2_IncludeGuard) && !defined(ExcludeExperimentalCode)
#define VariableListV2_IncludeGuard

#include "..\DLLAPI.h"
//Inside this ifdef block holds SharedCode Environment library version of header structure (preprocessor defined inside all SharedCode library configs)
#ifdef BLAZESSharedCode_LIBRARY

//Local Version of headers here(within else block)
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
#endif

#include <memory>

//Need to create smaller version of vector thats limited to 255 max elements later here

////Disable Auto-Resize Behavior(only increase Size to size needed for Elements)
//#define VariableListV2_DisableVectorLikeResize
//
//template <typename VariableType = unsigned __int8, typename ElementSizeType = unsigned __int8>
//class VariableListV2 : public VariableList <VariableType>//: public std::vector < VariableType >
//{
//	//size
//	/*
//		Notes on Mechanics of this class:
//		-Initialize Data as Size 1 array
//		-Any time data is added to array check to resize array
//		-Resize at element Index:
//		2,4,8,16
//
//		*/
//	//private:
//	//	VariableType LineData;
//	//	size_t StreamLine = -1;
////	using VariableType = unsigned __int8;
////	using ElementSizeType = unsigned __int8;
////	ElementSizeType Capacity = 1;
////public:
////	ElementSizeType Size = 0;
////	inline ElementSizeType GetSize()
////	{
////		return Size;
////	}
////	std::unique_ptr<VariableType[]> Data(VariableType[1]);
////	void Resize(ElementSizeType CapacityTemp)
////	{
////
////	}
//	//************************************
//	// Adds element into VariableList
//	// Method:    Add
//	// FullName:  VariableListV2::Add
//	// Access:    public
//	// Returns:   ElementSizeType
//	// Qualifier:
//	// Parameter: VariableType ElementValue
//	//************************************
//	//ElementSizeType Add(VariableType ElementValue)
//	//{
//	//	ElementSizeType Index = Size + 1;
//	//	if(Capacity<Index)
//	//	{
//	//		Resize(Index);
//	//	}
//
//	//}
//	//std::unique_ptr<VariableType[]> Data();
//	//std::unique_ptr<VariableType> Data(new VariableType(1));
//	//auto Data = unique_ptr<VariableType []>{ new VariableType[1] };
//
//	//VariableType ElementAt(ElementSizeType index)
//	//{
//	//	return Data
//	//}
//	//	//Returns the value at the specified index.
//	//	//************************************
//	//	// Method:    elementAt
//	//	// FullName:  VariableList<VariableType>::elementAt
//	//	// Access:    public
//	//	// Returns:   VariableType
//	//	// Qualifier:
//	//	// Parameter: int index
//	//	//************************************
//	//	VariableType elementAt(size_t index)
//	//	{
//	//		return at(index);
//	//	}
//	//	//	Returns the value at the specified index.
//	//	//************************************
//	//	// Method:    ElementAt
//	//	// FullName:  VariableList<VariableType>::ElementAt
//	//	// Access:    public
//	//	// Returns:   VariableType
//	//	// Qualifier:
//	//	// Parameter: int index
//	//	//************************************
//	//	VariableType ElementAt(size_t index)
//	//	{
//	//		return at(index);
//	//	}
//	//	//	Adds Value at end of vector
//	//	//************************************
//	//	// Method:    Add
//	//	// FullName:  VariableList<VariableType>::Add
//	//	// Access:    public
//	//	// Returns:   void
//	//	// Qualifier:
//	//	// Parameter: VariableType TempValue
//	//	//************************************
//	//	void Add(VariableType TempValue)
//	//	{
//	//		push_back(TempValue);
//	//	}
//	//	// Assign Value at index in vector (Alias for setElementAt)
//	//	//************************************
//	//	// Method:    Set
//	//	// FullName:  VariableList<VariableType>::Set
//	//	// Access:    public
//	//	// Returns:   void
//	//	// Qualifier:
//	//	// Parameter: int index
//	//	// Parameter: VariableType ElementValue
//	//	//************************************
//	//	void Set(int index, VariableType ElementValue)
//	//	{
//	//		return SetElementAt(index, ElementValue);
//	//	}
//	//	// (Alias for returning size of vector)
//	//	//************************************
//	//	// Method:    length
//	//	// FullName:  VariableList<VariableType>::length
//	//	// Access:    public
//	//	// Returns:   size_t
//	//	// Qualifier:
//	//	//************************************
//	//	size_t length()
//	//	{
//	//		return size();
//	//	}
//	//	//Returns the length of this string.(alias for size()) (size_t = unsigned long long int)
//	//	//************************************
//	//	// Method:    Size
//	//	// FullName:  VariableList<VariableType>::Size
//	//	// Access:    public
//	//	// Returns:   size_t
//	//	// Qualifier:
//	//	//************************************
//	//	size_t Size()
//	//	{
//	//		return size();
//	//	}
//	//	//Returns true if, and only if, length() is 0.
//	//	//************************************
//	//	// Method:    isEmpty
//	//	// FullName:  VariableList<VariableType>::isEmpty
//	//	// Access:    public
//	//	// Returns:   bool
//	//	// Qualifier:
//	//	//************************************
//	//	bool isEmpty()
//	//	{
//	//		return empty();
//	//	}
//	//	//************************************
//	//	// Method:    Reset
//	//	// FullName:  VariableList<VariableType>::Reset
//	//	// Access:    public
//	//	// Returns:   void
//	//	// Qualifier:
//	//	//************************************
//	//	void Reset()
//	//	{
//	//		if(!isEmpty())
//	//		{
//	//			clear();
//	//		}
//	//	}
//	//	//************************************
//	//	// Method:    PrintVectorLines
//	//	// FullName:  VariableList<VariableType>::PrintVectorLines
//	//	// Access:    public
//	//	// Returns:   void
//	//	// Qualifier:
//	//	//************************************
//	//	void PrintVectorLines()
//	//	{
//	//		if(!isEmpty())
//	//		{
//	//			int TempInt = size();
//	//			for(int i = 0; i < TempInt; i++)
//	//			{
//	//				ostringstream out;
//	//				out << elementAt(i);
//	//			}
//	//		}
//	//	}
//	//
//	//	/**
//	//	* Current StreamLine Outputted by StreamLineData();(-1=currently not streaming data)
//	//	* @return
//	//	*/
//	//	int GetStreamLine()
//	//	{
//	//		return StreamLine;
//	//	}
//	//
//	//	/**
//	//	* Current LineData Streamed from StreamLineData()
//	//	* @return VariableType
//	//	*/
//	//	VariableType CurrentStreamedLineString()
//	//	{
//	//		if(StreamLine == -1)
//	//		{
//	//			SetLineData(elementAt(0));
//	//		}
//	//		return LineData;
//	//	}
//	//
//	//	/*
//	//
//	//	*/
//	//	void SetLineData(VariableType TempValue)
//	//	{
//	//		LineData = TempValue;
//	//	}
//	//
//	//	/**
//	//	* Stream Data from VariableTypeList into LineString(place inside while loop to output data)
//	//	Example Loop:
//	//	for (LineNumber = 0; FileString.StreamLineData(); LineNumber++)
//	//	{
//	//	LineString = FileString.CurrentStreamedLineString();
//	//	}
//	//	*/
//	//	bool StreamLineData()
//	//	{
//	//		if(StreamLine == -1)
//	//		{//Start Data Stream
//	//			if(Size() == 0)
//	//			{//No Data to Stream
//	//				return false;
//	//			}
//	//			else
//	//			{
//	//				StreamLine = 0;
//	//				SetLineData(elementAt(0));
//	//				return true;
//	//			}
//	//		}
//	//		else
//	//		{
//	//			StreamLine++;
//	//			if(StreamLine < Size())
//	//			{
//	//				SetLineData(elementAt(StreamLine));
//	//				return true;
//	//			}
//	//			else
//	//			{
//	//				StreamLine = -1;
//	//				return false;
//	//			}
//	//		}
//	//	}
//	//	/**
//	//	* Returns true if Element exists with ElementValue
//	//	* @param Index
//	//	* @return
//	//	*/
//	//	bool ElementExists(VariableType ElementValue)
//	//	{
//	//		size_t ArraySize = Size();
//	//		bool ElementFound = false;
//	//		VariableType ElementTemp;
//	//		for(size_t i = 0; i < ArraySize&&ElementFound == false; ++i)
//	//		{
//	//			ElementTemp = ElementAt(i);
//	//			if(ElementTemp == ElementValue)
//	//			{
//	//				ElementFound = true;
//	//			}
//	//		}
//	//		return ElementFound;
//	//	}
//	//	/**
//	//	* Find first matching element containing the ElementValue;Returns -1 if no element matches
//	//	* @param ElementValue
//	//	* @return
//	//	*/
//	//	size_t GetElementIndex(VariableType ElementValue)
//	//	{
//	//		size_t ElementIndex = -1;
//	//		size_t ArraySize = Size();
//	//		bool ElementFound = false;
//	//		VariableType ElementTemp;
//	//		for(size_t i = 0; (i < ArraySize)&&!ElementFound; ++i)
//	//		{
//	//			ElementTemp = at(i);
//	//			if(ElementTemp == ElementValue)
//	//			{
//	//				ElementIndex = i;
//	//				ElementFound = true;
//	//			}
//	//		}
//	//		return ElementIndex;
//	//	}
//	//
//	//	/**
//	//	* Load file data from each line into VariableList if std::string is can be converted into VariableType
//	//	* @param Path:file-path to load data from
//	//	*/
//	//	void LoadFileData(std::string Path)
//	//	{
//	//		Reset();
//	//		std::string LineString;
//	//		std::string TypeString;
//	//		TypeString = typeid(VariableType).name();
//	//		VariableType ElementTemp;
//	//		std::fstream LoadedFileStream;
//	//		LoadedFileStream.open(Path, std::ios::in);
//	//		bool StreamingFileCheck = true;
//	//		if(LoadedFileStream.is_open())
//	//		{
//	//			while(StreamingFileCheck)
//	//			{
//	//				getline(LoadedFileStream, LineString);
//	//				if(LoadedFileStream.good())
//	//				{
//	//					if(TypeString == "int")
//	//					{
//	//						ElementTemp = StringFunctions::ReadIntFromString(LineString);
//	//					}
//	//					else if(TypeString == "bool")
//	//					{
//	//						ElementTemp = StringFunctions::ReadBoolFromString(LineString);
//	//					}
//	//					else if(TypeString == "double")
//	//					{
//	//						ElementTemp = StringFunctions::ReadDoubleFromString(LineString);
//	//					}
//	//					else if(TypeString == "string")
//	//					{
//	//						ElementTemp = LineString;
//	//					}
//	//					Add(LineString);
//	//				}
//	//				else
//	//				{
//	//					StreamingFileCheck = false;
//	//					if(LoadedFileStream.eof()) {/*Send debug message of reaching end of file?*/ }
//	//					else if(LoadedFileStream.bad())
//	//					{
//	//						/*Send Failed Read/Write operation Error message? */
//	//						std::cout << "Failed Read/Write Error on File Open with path" << Path<<"\n";
//	//						system("pause");
//	//					}
//	//					else if(LoadedFileStream.fail()) {/*Send Failed format based Error message? */ }
//	//				}
//	//			}
//	//			LoadedFileStream.close();
//	//		}
//	//	}
//	//	//Increase Position in StreamedLine
//	//	void AdvanceLineStream(int Temp)
//	//	{
//	//		StreamLine += Temp;
//	//	}
//	//	//Set Position in StreamedLine
//	//	void SetStreamPosition(int Temp)
//	//	{
//	//		if(Temp < Size())
//	//		{
//	//			StreamLine = Temp;
//	//		}
//	//	}
//	//	//Resets StreamLine to zero
//	//	void ResetStreamData()
//	//	{
//	//		SetStreamPosition(-1);
//	//	}
//	//	// Remove element from index position in vector(returns true if successful)
//	//	void Remove(size_t index)
//	//	{
//	//		//Code based on example listed on http://www.cplusplus.com/reference/vector/vector/erase/
//	//		erase(this->begin() + index);
//	//	}
//	//	//Alias for Remove()
//	//	void RemoveElement(size_t index)
//	//	{
//	//		Remove(index);
//	//	}
//	//	//Alternative version of Remove with index check
//	//	bool RemoveWithCheck(size_t index)
//	//	{
//	//		size_t TempInt;
//	//		TempInt = Size();
//	//		if(index < TempInt&&index >= 0)
//	//		{
//	//			erase(this->begin() + index);
//	//			return true;
//	//		}
//	//		else
//	//		{
//	//			cout << "Error:Failed to remove element from vector because of invalid index\n";
//	//			return false;
//	//		}
//	//	}
//	//	//	Add ElementValue at position:index in vector
//	//	void AddElementToIndex(size_t index, VariableType ElementValue)
//	//	{
//	//		this->emplace(this->begin() + index, ElementValue);
//	//	}
//	//	//	Add ElementValue at position:index in vector
//	//	void Add(size_t index, VariableType TempValue)
//	//	{
//	//		AddElementToIndex(index, ElementValue);
//	//	}
//	//	/**Assign ElementValue at index in vector*/
//	//	void SetElementAt(size_t index, VariableType ElementValue)
//	//	{
//	//		//Based on posted solution at:http://stackoverflow.com/questions/2624232/how-to-change-a-particular-element-of-a-c-stl-vector
//	//		this->at(index) = ElementValue;
//	//	}
//	//	//Alias for SetElementAt
//	//	void setElementAt(size_t index, VariableType ElementValue)
//	//	{
//	//		SetElementAt(index, ElementValue);
//	//	}
//	//	//Add basic initialyzed Element to list;Returns index of new element
//	//	size_t AddData()
//	//	{
//	//		size_t Index = Size();
//	//		VariableType TempValue;
//	//		Add(TempValue);
//	//		return Index;
//	//	}
//	//	//************************************
//	//	// Returns Element at index then removes it from VariableList
//	//	// Method:    RetrieveElementAtIndex
//	//	// FullName:  VariableList<VariableType>::RetrieveElementAtIndex
//	//	// Access:    public
//	//	// Returns:   VariableType
//	//	// Qualifier:
//	//	// Parameter: int index
//	//	//************************************
//	//	VariableType RetrieveElementAtIndex(size_t index)
//	//	{
//	//		VariableType ElementData;
//	//		if(index < Size())
//	//		{
//	//			ElementData = this->ElementAt(index);
//	//			this->Remove(index);
//	//		}
//	//		return ElementData;
//	//	}
//	//	//Return equivalent index of element(TargetIndex) from TargetVariableList in Current VariableList;Returns -1 if no match found
//	//	size_t ReturnNewVariableIndex(VariableList TargetVariableList, size_t TargetIndex)
//	//	{
//	//		size_t index = -1;
//	//		if(TargetIndex < TargetVariableList.Size() && TargetIndex >= 0)
//	//		{
//	//			VariableType TargetElementData = TargetVariableList.ElementAt(TargetIndex);
//	//			index = this->GetElementIndex(TargetElementData);
//	//		}
//	//		return index;
//	//	}
//	//	//Add Element if not already inside VariableList
//	//	bool AddIfNotExist(VariableType TempValue)
//	//	{
//	//		if(ElementExists(TempValue) == false)
//	//		{
//	//			Add(TempValue);
//	//			return true;
//	//		}
//	//		return false;
//	//	}
//	//	//Combine Elements from TargetVariableList into VariableList
//	//	void CombineNonExistantElements(VariableList TargetVariableList)
//	//	{
//	//		size_t TempInt = TargetVariableList.Size();
//	//		VariableType TargetElementData;
//	//		for(size_t i = 0; i < TempInt; ++i)
//	//		{
//	//			TargetElementData = TargetVariableList.ElementAt(i);
//	//			AddIfNotExist(TargetElementData);
//	//		}
//	//	}
//	//	//Combine All Elements from TargetVariableList into VariableList
//	//	void CombineAllElements(VariableList TargetVariableList)
//	//	{
//	//		size_t TempInt = TargetVariableList.Size();
//	//		VariableType TargetElementData;
//	//		for(int i = 0; i < TempInt; i++)
//	//		{
//	//			TargetElementData = TargetVariableList.ElementAt(i);
//	//			Add(TargetElementData);
//	//		}
//	//	}
//	//	//Return shared pointer to Element Index in array
//	//	//************************************
//	//	// Method:    GetElementSharedPointer
//	//	// FullName:  VariableList<VariableType>::GetElementSharedPointer
//	//	// Access:    public
//	//	// Returns:   std::shared_ptr<VariableType>
//	//	// Qualifier:
//	//	// Parameter: int index
//	//	//************************************
//	//	std::shared_ptr<VariableType> GetElementSharedPointer(size_t index)
//	//	{
//	//		VariableType* ArrayPointer = myvector.data();
//	//		return *ArrayPointer[index];
//	//	}
//	//	//Return Pointer to Element Index in array. Returns nullptr if use invalid Index.(Tested to not work with VariableList<Variable> Lists)
//	//	//************************************
//	//	// Method:    GetElementPointer
//	//	// FullName:  VariableList<VariableType>::GetElementPointer
//	//	// Access:    public
//	//	// Returns:   VariableType*
//	//	// Qualifier:
//	//	// Parameter: int index
//	//	//************************************
//	//	VariableType* GetElementPointer(size_t index)
//	//	{
//	//		if(index < Size())
//	//		{
//	//			VariableType* ArrayPointer = myvector.data();
//	//			return *ArrayPointer[index];
//	//		}
//	//		else
//	//		{
//	//			std::cout << "Error:Attempting to retrieve pointer from out of bounds index. Sending Nullptr value instead.\n";
//	//			return nullptr;
//	//		}
//	//	}
//	//	//Alternative function for return Pointer to Element Index in array. Returns nullptr if use invalid Index.(Tested to work with VariableList<Variable> Lists)
//	//	//************************************
//	//	// Method:    GetElementPointerV2
//	//	// FullName:  VariableList<VariableType>::GetElementPointer
//	//	// Access:    public
//	//	// Returns:   VariableType*
//	//	// Qualifier:
//	//	// Parameter: int index
//	//	//************************************
//	//	VariableType* GetElementPointerV2(size_t index)
//	//	{
//	//		if(index < Size())
//	//		{
//	//			VariableList::iterator VectorIterator;
//	//			VectorIterator = this->begin() + index;
//	//			return &(*VectorIterator);
//	//		}
//	//		else
//	//		{
//	//			std::cout << "Error:Attempting to retrieve pointer from out of bounds index. Sending Nullptr value instead.\n";
//	//			return nullptr;
//	//		}
//	//	}
//	//	std::vector<VariableType> CastAsVector()
//	//	{
//	//		vector <VariableType> NewVector;
//	//		const size_t SizeTemp = Size();
//	//		VariableType* CurrentElement;
//	//		for(size_t Index = 0; Index < SizeTemp;++Index)
//	//		{
//	//			CurrentElement = GetElementPointerV2(Index);
//	//			NewVector.push_back(CurrentElement);
//	//		}
//	//		return NewVector;
//	//	}
//	//	void RemoveElementWithMatchingValue(VariableType ElementValue)
//	//	{
//	//		size_t TargetElementIndex = GetElementIndex(ElementValue);
//	//		if(TargetElementIndex!=-1)
//	//		{
//	//			Remove(TargetElementIndex);
//	//		}
//	//	}
//	//	//************************************
//	//	// Method:    VariableList
//	//	// FullName:  VariableList<VariableType>::VariableList
//	//	// Access:    public
//	//	// Returns:
//	//	// Qualifier:
//	//	VariableList()
//	//	{
//	//		StreamLine = -1;
//	//	}
//	//	~VariableList()
//	//	{}
//	//	VariableList(std::string FileString)
//	//	{
//	//		StreamLine = -1;
//	//		LoadFileData(FileString);
//	//	}
//};
#endif
