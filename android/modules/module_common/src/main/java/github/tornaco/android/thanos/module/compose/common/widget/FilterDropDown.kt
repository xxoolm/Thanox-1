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

package github.tornaco.android.thanos.module.compose.common.widget

import android.content.Context
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.wrapContentSize
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.DropdownMenuItem
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.FilledTonalButton
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp

interface FilterItem {
    val id: String
    val label: (Context) -> String
}

@Composable
fun <T : FilterItem> FilterDropDown(
    icon: ImageVector? = null,
    selectedItem: T?,
    allItems: List<T>,
    onItemSelected: (T) -> Unit = {},
) {
    val context = LocalContext.current
    if (selectedItem != null && allItems.isNotEmpty()) {
        Box(
            modifier = Modifier.wrapContentSize(Alignment.TopStart)
        ) {
            var expanded by remember { mutableStateOf(false) }
            FilledTonalButton(
                onClick = { expanded = true }) {
                icon?.let {
                    Icon(
                        it,
                        contentDescription = "FilterDropDown",
                        modifier = Modifier.size(ButtonDefaults.IconSize)
                    )
                    Spacer(Modifier.size(4.dp))
                }
                Text(
                    text = selectedItem.label(context),
                    style = MaterialTheme.typography.labelLarge
                )
            }
            MaterialTheme(
                shapes = MaterialTheme.shapes.copy(extraSmall = RoundedCornerShape(18.dp))
            ) {
                androidx.compose.material3.DropdownMenu(
                    modifier = Modifier.background(MaterialTheme.colorScheme.surface),
                    expanded = expanded,
                    onDismissRequest = { expanded = false }
                ) {
                    allItems.forEach { item ->
                        DropdownMenuItem(onClick = {
                            onItemSelected(item)
                            expanded = false
                        }) {
                            Text(text = item.label(context))
                        }
                    }
                }
            }

        }
    }
}
