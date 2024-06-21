/*
 * (C) Copyright 2022 Thanox
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

package now.fortuitous.thanos

import android.content.Context
import android.os.Build
import com.elvishew.xlog.XLog
import dagger.hilt.android.HiltAndroidApp
import github.tornaco.android.thanos.MultipleModulesApp
import github.tornaco.android.thanos.common.AppItemViewLongClickListener
import github.tornaco.android.thanos.common.CommonAppListFilterAdapter
import github.tornaco.android.thanos.core.app.AppGlobals
import github.tornaco.android.thanos.feature.access.AppFeatureManager
import github.tornaco.android.thanos.main.launchSubscribeActivity
import github.tornaco.thanos.module.component.manager.initRules
import io.reactivex.plugins.RxJavaPlugins
import now.fortuitous.app.Init
import now.fortuitous.app.Stats
import org.lsposed.hiddenapibypass.HiddenApiBypass
import tornaco.apps.thanox.ThanosLite

@HiltAndroidApp
class ThanosApp : MultipleModulesApp() {
    override fun attachBaseContext(base: Context) {
        super.attachBaseContext(base)
        AppGlobals.setContext(base)
        this.installCrashHandler()
    }

    override fun onCreate() {
        AppGlobals.setContext(this.applicationContext)
        super.onCreate()

        // Install error handler.
        // Error handler default print error info.
        RxJavaPlugins.setErrorHandler { throwable: Throwable? ->
            XLog.e("\n")
            XLog.e("==== App un-handled error, please file a bug ====")
            XLog.e(throwable)
            XLog.e("\n")
        }

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            HiddenApiBypass.addHiddenApiExemptions("")
        }

        Init.init(this)
        AppFeatureManager.launchSubscribeActivity = { launchSubscribeActivity(it) {} }
        Stats.init(this)
        // TODO Async init.
        initRules(this.applicationContext)
        XposedScope.init()

        CommonAppListFilterAdapter.fallbackAppItemLongClickListener =
            AppItemViewLongClickListener { _, model ->
                model?.appInfo?.let {
                    now.fortuitous.thanos.apps.AppDetailsActivity.start(this@ThanosApp, it)
                }
            }

        ThanosLite.init(this)
    }
}