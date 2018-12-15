#pragma once

#include <memory>
#include <string_view>

namespace variables
{
  struct ITreeItem
  {
    using Ptr = std::shared_ptr<ITreeItem>;
    virtual ~ITreeItem() = default;

    virtual std::string_view Path() const = 0;
    virtual std::int32_t Id() const = 0;

    virtual void Accept( struct ITreeItemVisitor & visitor ) = 0;
  };

  template<typename T>
  struct IVariable : ITreeItem
  {
    virtual T GetValue() const = 0;
    virtual void Set( T value ) = 0;
  };

  struct IGroup : ITreeItem
  {
    virtual void Add( ITreeItem::Ptr const & item ) = 0;
    virtual void ForEachItem( struct IGroupCallback const & callbcak ) = 0;
    virtual std::size_t Size() const noexcept = 0;
    virtual ITreeItem::Ptr GetItem( std::size_t id ) = 0;
    virtual ITreeItem::Ptr GetItem( std::string_view path ) = 0;
  };

  struct IGroupCallback
  {
    using Ptr = std::unique_ptr<IGroupCallback>;

    virtual ~IGroupCallback() = default;
    virtual void OnItem( std::size_t id, ITreeItem const & item ) = 0;
  };
}
