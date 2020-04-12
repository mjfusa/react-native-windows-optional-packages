using Microsoft.ReactNative.Managed;
using Windows.Security.ExchangeActiveSyncProvisioning;

namespace DWWRC
{
    [ReactModule]
    class SampleComponent
    {
        [ReactMethod("getDeviceModel")]
        public string GetDeviceModel()
        {
            EasClientDeviceInformation info = new EasClientDeviceInformation();
            return info.SystemProductName;
        }
    }
}
