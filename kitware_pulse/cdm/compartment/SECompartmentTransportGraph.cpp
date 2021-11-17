/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "compartment/SECompartmentTransportGraph.h"

template<COMPARTMENT_TRANSPORT_GRAPH_TEMPLATE>
SECompartmentTransportGraph<COMPARTMENT_TRANSPORT_GRAPH_TYPES>::SECompartmentTransportGraph(const std::string& name, Logger* logger) : SECompartmentGraph<COMPARTMENT_GRAPH_TYPES>(name,logger)
{
  
}
template<COMPARTMENT_TRANSPORT_GRAPH_TEMPLATE>
SECompartmentTransportGraph<COMPARTMENT_TRANSPORT_GRAPH_TYPES>::~SECompartmentTransportGraph()
{
  Clear();
}

template<COMPARTMENT_TRANSPORT_GRAPH_TEMPLATE>
void SECompartmentTransportGraph<COMPARTMENT_TRANSPORT_GRAPH_TYPES>::Clear()
{
  SECompartmentGraph<COMPARTMENT_GRAPH_TYPES>::Clear();
  for (auto& itr : m_TargetEdgeMap)
    delete itr.second;
  for (auto& itr : m_SourceEdgeMap)
    delete itr.second;
  m_Verticies.clear();
  m_VertexIndicies.clear();
  m_TargetEdgeMap.clear();
  m_SourceEdgeMap.clear();
}

template<COMPARTMENT_TRANSPORT_GRAPH_TEMPLATE>
void SECompartmentTransportGraph<COMPARTMENT_TRANSPORT_GRAPH_TYPES>::StateChange()
{
  for (auto& itr : m_TargetEdgeMap)
    delete itr.second;
  for (auto& itr : m_SourceEdgeMap)
    delete itr.second;
  m_TargetEdgeMap.clear();
  m_SourceEdgeMap.clear();
  // Cache what paths are connected to what nodes
  for (CompartmentLinkType* link : this->m_CompartmentLinks)
  {
    CompartmentType* cSrc = &link->GetSourceCompartment();
    CompartmentType* cTgt = &link->GetTargetCompartment();
    // Source Edges
    std::vector<GraphEdgeType*>* srcEdges = m_SourceEdgeMap[cSrc];
    if (srcEdges == nullptr)
    {
      srcEdges = new std::vector<GraphEdgeType*>();
      m_SourceEdgeMap[cSrc] = srcEdges;
    }
    srcEdges->push_back(link);
    // Target Edges
    std::vector<GraphEdgeType*>* tgtEdges = m_TargetEdgeMap[cTgt];
    if (tgtEdges == nullptr)
    {
      tgtEdges = new std::vector<GraphEdgeType*>();
      m_TargetEdgeMap[cTgt] = tgtEdges;
    }
    tgtEdges->push_back(link);
  }
  // Now push the compartments into graph lists for transport
  int i = 0;
  m_Verticies.clear();
  m_VertexIndicies.clear();
 for (CompartmentType* c : this->m_Compartments)
  {
    m_Verticies.push_back(c);
    m_VertexIndicies[c] = i++;
  }
}

template<COMPARTMENT_TRANSPORT_GRAPH_TEMPLATE>
size_t SECompartmentTransportGraph<COMPARTMENT_TRANSPORT_GRAPH_TYPES>::GetVertexIndex(const GraphVertexType& v) const
{
  auto itr = m_VertexIndicies.find(&v);
  if (itr == m_VertexIndicies.end())
  {
    this->Error("Vertex is not in Graph Index Map.");
    return -1;
  }
  return itr->second;
}
template<COMPARTMENT_TRANSPORT_GRAPH_TEMPLATE>
const std::vector<GraphVertexType*>& SECompartmentTransportGraph<COMPARTMENT_TRANSPORT_GRAPH_TYPES>::GetVerticies() const
{
  return m_Verticies;
}
template<COMPARTMENT_TRANSPORT_GRAPH_TEMPLATE>
const std::vector<GraphEdgeType*>* SECompartmentTransportGraph<COMPARTMENT_TRANSPORT_GRAPH_TYPES>::GetSourceEdges(const GraphVertexType& v) const
{
  auto itr = m_SourceEdgeMap.find(&v);
  if (itr == m_SourceEdgeMap.end())
    return nullptr;
  return itr->second;
}
template<COMPARTMENT_TRANSPORT_GRAPH_TEMPLATE>
const std::vector<GraphEdgeType*>* SECompartmentTransportGraph<COMPARTMENT_TRANSPORT_GRAPH_TYPES>::GetTargetEdges(const GraphVertexType& v) const
{
  auto itr = m_TargetEdgeMap.find(&v);
  if (itr == m_TargetEdgeMap.end())
    return nullptr;
  return itr->second;
}

#include "compartment/fluid/SEGasCompartmentGraph.h"
template class SECompartmentTransportGraph<SEGasTransportGraph, SEGasTransportVertex, SEGasTransportEdge, SEGasCompartment, SEGasCompartmentLink>;
#include "compartment/fluid/SELiquidCompartmentGraph.h"
template class SECompartmentTransportGraph<SELiquidTransportGraph, SELiquidTransportVertex, SELiquidTransportEdge, SELiquidCompartment, SELiquidCompartmentLink>;
