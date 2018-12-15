#pragma once

#include <Variables/TreeItem.h>

namespace variables
{
  struct IChangeCallback
  {
    using Ptr = std::shared_ptr<IChangeCallback>;
    virtual ~IChangeCallback() = default;

    virtual void OnAdded( IGroup const & parentGroup, ITreeItem const & addedItem ) = 0;
    virtual void OnRemoved( IGroup const & parentGroup, ITreeItem const & removedItem ) = 0;
    virtual void OnChanged( ITreeItem const & changedItem ) = 0;
  };

  struct ITree
  {
    using Ptr = std::shared_ptr<ITree>;
    virtual ~ITree() = default;

    virtual IGroup & Root() = 0;
    virtual IGroup const & Root() const = 0;
    virtual void Subscribe( IChangeCallback::Ptr const & changesHandler ) = 0;
  };
}
