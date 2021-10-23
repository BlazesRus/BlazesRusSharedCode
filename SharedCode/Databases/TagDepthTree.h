//	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
//	Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
//
#pragma once
#ifndef TagDepthTree_Header
#define TagDepthTree_Header

#ifndef DLL_API
#ifdef UsingBlazesSharedCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESSharedCode_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif

#include <string>
#include <vector>

namespace BlazesRusCode
{
    class DLL_API TagElement
    {
    private:
        /// <summary>
        /// Prevents a default instance of the <see cref="TagElement"/> class from being created.
        /// </summary>
        TagElement()
        {
            NodeIndex = 0;
            NodeName = "";
        }
    public:
        /// <summary>
        /// The node index (Could also easily act as a key to ordered map)
        /// </summary>
        unsigned int NodeIndex;
        /// <summary>
        /// The node name
        /// </summary>
        std::string NodeName;
        /// <summary>
        /// Initializes a new instance of the <see cref="TagElement"/> class.
        /// </summary>
        /// <param name="nodeName">Name of the node.</param>
        /// <param name="nodeIndex">Index of the node.</param>
        TagElement(std::string nodeName, unsigned int nodeIndex)
        {
            NodeName = nodeName;
            NodeIndex = nodeIndex;
        }
    };

    /// <summary>
    /// Class named TagDepthTree that keeps track of matching tags to keep track of which node(s) to exit).
    /// Implements the <see cref="std::vector{TagElement}" />
    /// </summary>
    /// <seealso cref="std::vector{TagElement}" />
    class TagDepthTree : public std::vector<TagElement>
    {
    public:
        /// <summary>
        /// Adds the tag.
        /// </summary>
        /// <param name="nodeIndex">Index of the node.</param>
        /// <param name="nodeName">Name of the node.</param>
        void AddTag(unsigned int nodeIndex, std::string nodeName)
        {
            TagElement NewTag(nodeName, nodeIndex);
            this->push_back(NewTag);
        }

        /// <summary>
        /// Cycle in reverse to find first match then remove.
        /// </summary>
        /// <param name="tagName">Name of the tag.</param>
        /// <returns>Index of Tag Match</returns>
        unsigned int RemoveLastTagMatch(std::string tagName)
        {
            unsigned int nodeIndex = 0;
            for (TagDepthTree::reverse_iterator i = this->rbegin(), TreeEnd = this->rend(); nodeIndex == 0 && i != TreeEnd; ++i)
            {
                if (i->NodeName == tagName)
                {
                    nodeIndex = i->NodeIndex;
                    std::advance(i, 1);//Based on https://stackoverflow.com/questions/1830158/how-to-call-erase-with-a-reverse-iterator
                    this->erase(i.base());
                }
            }
            return nodeIndex;
        }
    };
}
#endif