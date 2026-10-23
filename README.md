# MyDLLDemo

Following the Unreal Engine DLL lecture slides, a native C++ DLL (`MyMod.dll`) was built in Visual Studio 2022 with functions for setting a preferred language and calculating movement speed. The DLL was imported into Unreal Engine 5.8 using a C++ wrapper (`MyModLibrary`) to access its functions through Blueprints, along with a C++ Actor (`DLLTestActor`) to test the speed calculation. The debug output confirmed that the DLL loaded successfully, returned the language `fr`, and calculated a movement speed of 900.

Blurprints Screenshot - 
<img width="833" height="308" alt="Screenshot 2026-10-23 193345" src="https://github.com/user-attachments/assets/53a22e89-1b75-4b05-9e7e-59f3b979f308" />

Code Screenshot -
<img width="861" height="493" alt="Screenshot 2026-10-23 193407" src="https://github.com/user-attachments/assets/d4dadfe4-e501-4458-95c5-87bc463d4eef" />

Output - 
<img width="886" height="365" alt="Screenshot 2026-10-22 224307" src="https://github.com/user-attachments/assets/9b0fb3a8-50f3-40db-87ea-3cd90837f017" />

<img width="461" height="46" alt="image" src="https://github.com/user-attachments/assets/c38feb55-a0f4-49a0-af28-26aa2227933f" />

