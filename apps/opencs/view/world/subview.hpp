#ifndef CSV_WORLD_SUBVIEW_H
#define CSV_WORLD_SUBVIEW_H

#include "../../model/world/universalid.hpp"

#include <QDockWidget>

namespace CSMWorld
{
    class Data;
}

namespace CSVWorld
{
    class SubView : public QDockWidget
    {
            Q_OBJECT

            CSMWorld::UniversalId mUniversalId;

            // not implemented
            SubView (const SubView&);
            SubView& operator= (SubView&);

        public:

            SubView (const CSMWorld::UniversalId& id);

            CSMWorld::UniversalId getUniversalId() const;
    };

    struct SubViewFactoryBase
    {
        virtual SubView *makeSubView (const CSMWorld::UniversalId& id, CSMWorld::Data& data) = 0;
    };

    template<class SubViewT>
    struct SubViewFactory : public SubViewFactoryBase
    {
        virtual SubView *makeSubView (const CSMWorld::UniversalId& id, CSMWorld::Data& data);
    };

    template<class SubViewT>
    SubView *SubViewFactory<SubViewT>::makeSubView (const CSMWorld::UniversalId& id, CSMWorld::Data& data)
    {
        return new SubViewT (id, data);
    }
}

#endif