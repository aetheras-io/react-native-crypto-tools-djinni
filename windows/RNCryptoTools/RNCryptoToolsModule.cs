using ReactNative.Bridge;
using System;
using System.Collections.Generic;
using Windows.ApplicationModel.Core;
using Windows.UI.Core;

namespace Crypto.Tools.RNCryptoTools
{
    /// <summary>
    /// A module that allows JS to share data.
    /// </summary>
    class RNCryptoToolsModule : NativeModuleBase
    {
        /// <summary>
        /// Instantiates the <see cref="RNCryptoToolsModule"/>.
        /// </summary>
        internal RNCryptoToolsModule()
        {

        }

        /// <summary>
        /// The name of the native module.
        /// </summary>
        public override string Name
        {
            get
            {
                return "RNCryptoTools";
            }
        }
    }
}
