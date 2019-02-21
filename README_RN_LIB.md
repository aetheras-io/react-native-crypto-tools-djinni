# react-native-crypto-tools

## Getting started

`$ npm install react-native-crypto-tools --save`

### Mostly automatic installation

`$ react-native link react-native-crypto-tools`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-crypto-tools` and add `RNCryptoTools.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNCryptoTools.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainApplication.java`
  - Add `import com.reactlibrary.RNCryptoToolsPackage;` to the imports at the top of the file
  - Add `new RNCryptoToolsPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-crypto-tools'
  	project(':react-native-crypto-tools').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-crypto-tools/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-crypto-tools')
  	```

#### Windows
[Read it! :D](https://github.com/ReactWindows/react-native)

1. In Visual Studio add the `RNCryptoTools.sln` in `node_modules/react-native-crypto-tools/windows/RNCryptoTools.sln` folder to their solution, reference from their app.
2. Open up your `MainPage.cs` app
  - Add `using Crypto.Tools.RNCryptoTools;` to the usings at the top of the file
  - Add `new RNCryptoToolsPackage()` to the `List<IReactPackage>` returned by the `Packages` method


## Usage
```javascript
import RNCryptoTools from 'react-native-crypto-tools';

// TODO: What to do with the module?
RNCryptoTools;
```
  