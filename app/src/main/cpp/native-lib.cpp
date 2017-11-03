#include <jni.h>
#include <string>

void callJavaMethod(JNIEnv *pEnv, jobject pJobject);

extern "C"

JNIEXPORT jstring JNICALL Java_ifreecomm_ndkdemo_MainActivity_fuck(JNIEnv *env, jobject instance) {

    // TODO
    std::string fuck = "玩你妹的NDK";

    return env->NewStringUTF(fuck.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_ifreecomm_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

void callJavaMethod(JNIEnv *env, jobject pJobject) {
    jclass clazz = env->FindClass("ifreecomm/ndkdemo/MainActivity");
    if (clazz == NULL) {
        printf("find class MainActivity error!");
        return;
    }
    jmethodID id = env->GetMethodID(clazz,"methodByJni","(Ljava/lang/String;)V");
    if(id == NULL){
        printf("find method error!");
        return;
    }
    jstring msg = env ->NewStringUTF("c++ 调用了java 的非静态方法");
    env->CallVoidMethod(pJobject,id,msg);


}


/*
 * 程序首先通过类名（ifreecomm/ndkdemo/MainActivity） 找到类，
 * 然后再根据方法名（methodByJni）找到方法
 * (Ljava/lang/String;)V  是methodByJni 方法的签名
 * */
void callStaticJavaMethod(JNIEnv *env, jobject thiz) {
    jclass clazz = env->FindClass("ifreecomm/ndkdemo/MainActivity");
    if (clazz == NULL) {
        printf("find class MainActivity error!");
        return;
    }
    jmethodID id =  env->GetStaticMethodID(clazz,"staticMethodByJni","(Ljava/lang/String;)V");
    if(id == NULL){
        printf("find method error!");
        return;
    }
    jstring msg = env ->NewStringUTF("c++ 调用了java 的 静态方法");
    env->CallStaticVoidMethod(clazz,id,msg);

}

extern "C"
JNIEXPORT void JNICALL
Java_ifreecomm_ndkdemo_MainActivity_staticJniCallC(JNIEnv *env, jobject instance) {

    // TODO
    callStaticJavaMethod(env,instance);
}



extern "C"
JNIEXPORT void JNICALL
Java_ifreecomm_ndkdemo_MainActivity_jniCallC(JNIEnv *env, jobject instance) {

    // TODO
    callJavaMethod(env,instance);
}

